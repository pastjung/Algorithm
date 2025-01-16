#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> have(n + 1, 1); // 체육복 소지 여부
    
    // 여분의 체육복이 있는 경우
    for(int r : reserve) {
        have[r]++;
    }
    
    // 체육복을 잃어버린 경우
    for(int i : lost) {
        have[i]--;
    }
    
    // 체육복을 빌릴 수 있는지 확인
    for(int i = 1; i <= n; i++){
        if(have[i] == 0) {
            if(have[i - 1] == 2){
                have[i - 1]--;
                have[i]++;
            } else if (have[i + 1] == 2) {
                have[i + 1]--;
                have[i]++;
            }
        }
    }
    
    // 수업을 들을 수 있는 학생의 수
    for(int i = 1; i <= n; i++){
        if(have[i]) answer++;
    }
    
    return answer;
}