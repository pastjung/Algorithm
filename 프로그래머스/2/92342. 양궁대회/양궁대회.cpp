#include <string>
#include <vector>
using namespace std;

const int SCORE = 11;

// 백트래킹 함수
void backtracking(vector<int>& answer, vector<int>& info, vector<int>& ryan, int n, int cur, int& maxScore){
    // 기저 조건 : 11개의 점수를 모두 선택한 경우
    if(cur == SCORE){
        // 화살이 남은 경우 : 마지막 0점에 몰아주기
        if(n > 0){
            ryan[10] += n;
        }
        
        // 점수 계산
        int a = 0, r = 0;
        for(int i = 0; i < SCORE; i++){
            if (info[i] == 0 && ryan[i] == 0) continue; // 둘 다 0이면 무득점
            else if(info[i] < ryan[i]) r += 10 - i;
            else a += 10 - i;
        }
        
        // 최적 결과 갱신
        if(r > a){
            int diff = r - a;
            if(diff > maxScore){
                maxScore = diff;
                answer = ryan;
            } else if(diff == maxScore){
                for(int i = SCORE - 1; i >= 0; i--){
                    if(answer[i] == ryan[i]) continue;
                    if(answer[i] < ryan[i]) {
                        answer = ryan;
                    }
                    break;
                }    
            }
        }

        
        if (n > 0) ryan[10] -= n; // 복구
        return;
    }

    // 현재 점수를 선택하는 경우 : 해당 점수를 선택 가능한지 확인 (남은 화살의 개수 > 어피치가 k점을 맞춘 횟수)
    if(n > info[cur]){
        ryan[cur] += info[cur] + 1;                                                // 점수 획득
        backtracking(answer, info, ryan, n - info[cur] - 1, cur + 1, maxScore);    // 다음 점수로 재귀
        ryan[cur] = 0;                                                             // 점수 획득 취소 ( 백트래킹 )
    }
    
    // 현재 점수를 선택하지 않는 경우 ( 점수 포기 ) -> 재귀
    backtracking(answer, info, ryan, n, cur + 1, maxScore);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer = {-1};                     // 최적 결과를 저장할 배열 ( 가장 큰 점수차 -> 낮은 점수 기준 )
    vector<int> ryan(SCORE, 0);                    // 라이언이 맞힌 화살 개수를 저장할 배열
    int maxScore = 0;                              // 최대 점수 차이
    backtracking(answer, info, ryan, n, 0, maxScore);     // 백트래킹 시행
    return answer;
}