#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/* 문제 분석
- 문제 설명
    - n을 k진수로 바꿨을 때 변환된 수 안에 소수의 개수 파악
- 입력 데이터
    - 양의 정수 n
    - k 진수
- 핵심 키워드
    - 소수 정보 -> 0을 기준으로 분할
*/

// 소수 판별 함수
bool isPrime(long long num){
    if(num < 2){
        return false;
    } else if(num == 2){
        return true;
    } else {
        for(int i = 2; i <= sqrt(num); i++){
            if(num % i == 0) return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    int num = n;
    string number = "";
    
    // n을 k 진수로 변환 -> 이때 0을 기준으로 분할
    while(num > 0){
        int remain = num % k;
        num /= k;
        
        // 0P0 or P0인 경우
        if(remain == 0){
            reverse(number.begin(), number.end());
            if(number != "" && isPrime(stoll(number))){
                answer++;
                number = "";
            }
        } else {
            number += to_string(remain);
        }
    }
    // P or 0P 인 경우
    if(number != ""){
        reverse(number.begin(), number.end());
        if(isPrime(stoll(number))){
            answer++;    
        }
        
    }
    
    return answer;
}