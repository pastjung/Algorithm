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

// 백트래킹을 통한 소수 조합 찾기
void findPrimes(const string& numbers, string current, set<int>& primeNums, vector<bool>& visited) {
    if (!current.empty()) {
        int num = stoi(current);
        if (isPrime(num)) {
            primeNums.insert(num); // 소수일 경우 집합에 추가
        }
    }

    for (int i = 0; i < numbers.size(); ++i) {
        if (visited[i]) continue; // 이미 사용된 숫자는 무시
        visited[i] = true; // 숫자를 사용함
        findPrimes(numbers, current + numbers[i], primeNums, visited); // 백트래킹 호출
        visited[i] = false; // 백트래킹 후 숫자 사용 해제
    }
}

int solution(string numbers) {
    set<int> primeNums; // 중복 제거를 위한 set
    vector<bool> visited(numbers.size(), false); // 방문 여부 확인
    findPrimes(numbers, "", primeNums, visited); // 모든 조합 찾기
    return primeNums.size(); // 유일한 소수의 개수 반환
}