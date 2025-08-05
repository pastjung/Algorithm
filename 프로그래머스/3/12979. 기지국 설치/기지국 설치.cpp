#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;

    int start = 1;   // 전파가 닿지 않는 위치의 시작 위치
    int coverage = 2 * w + 1;  // 전파가 커버할 수 있는 길이
    
    // 전파가 닿지 않는 구간의 수 만큼 반복
    for(int station : stations){
        int left = station - w;     // 전파가 닿기 시작하는 위치
        int right = station + w;    // 전파가 닿는 위치가 끝나는 위치
        int len = left - start;     // 전파가 닿지 않는 위치의 길이
        
        // 전파가 닿지 않는 구간에 필요한 기지국 수 계산
        answer += (len + coverage - 1) / coverage;
        
        // 다음 구간 찾기 위해 탐색
        start = right + 1;
    }
    
    // 마지막 구간 확인
    if(start <= n){
        int len = n - start + 1;
        answer += (len + coverage - 1) / coverage;
    }

    return answer;
}