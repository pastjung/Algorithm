#include <string>
#include <vector>
#include <cmath>
using namespace std;

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
            if(number != "" && isPrime(stoll(number))){
                answer++;
            }
            number = "";
        } else {
            number = to_string(remain) + number;
        }
    }
    // P or 0P 인 경우
    if(number != ""){
        if(isPrime(stoll(number))){
            answer++;
        }   
    }
    
    return answer;
}