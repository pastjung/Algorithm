#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 정렬 조건 -> 두 문자열 조합이 더 큰 방향으로 정렬
bool cmp(int a, int b){
    string A = to_string(a);
    string B = to_string(b);
    return A + B > B + A;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    // 정렬된 값으로 문자열 생성
    for(int num : numbers){
        answer += to_string(num);
    }
    
    if(answer[0] == '0'){
        answer = "0";
    }
    
    return answer;
}