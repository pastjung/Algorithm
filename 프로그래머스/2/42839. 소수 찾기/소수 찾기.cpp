#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false; // 1 이하의 숫자는 소수가 아님
    if (num <= 3) return true;  // 2, 3은 소수
    if (num % 2 == 0 || num % 3 == 0) return false; // 2 또는 3의 배수는 소수가 아님

    for (int i = 5; i * i <= num; i += 6) { // 6k ± 1 패턴
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> primeNums; // 중복 제거를 위한 set
    
    for(int i = 1; i <= numbers.size(); i++){
        string temp = numbers;
        sort(temp.begin(), temp.end());
        do{
            string subStr = temp.substr(0, i);  // 부분 문자열 생성
            primeNums.insert(stoi(subStr));
        } while(next_permutation(temp.begin(), temp.end()));    // 순열 생성
    }
    
    for (int num : primeNums) {
        if (isPrime(num)) {
            answer++;
        }
    }
    
    return answer;
}