#include <string>
#include <vector>
#include <climits>
using namespace std;

/* 문제 분석
- 문제 설명
    - 코딩테스트 문제를 풀기 위해서는 알고력, 코딩력 필요
    - 알고력과 코딩력을 높이기 위한 방법
        - 1의 시간으로 알고력 or 코딩력 공부
        - 현재 풀 수 있는 문제 중 하나를 풀어 알고력과 코딩력 향상
    - 모든 문제들을 풀 수 있는 알고력과 코딩력을 얻는 최단 시간 구하기
- 입력 데이터
    - 초기 알고력 alp
    - 초기 코딩력 cop
    - 문제의 정보를 담은 2차원 배열 problems
- 핵심 키워드
    - 고정된 데이터: 알고력, 코딩력 -> dp 테이블의 index -> dp[alp][cop] = 해당 능력을 얻는 최단 시간
    - 모든 문제를 풀 수 있는 알고력과 코딩력은 각 문제의 최대값
    - 각 문제의 최대 알고력&코딩력을 넘는 값은 문제의 최대치인 값에 전부 저장
*/

int maxAbility(const vector<vector<int>>& problems, int idx){
    int result = 0;
    for(vector<int> problem : problems){
        result = max(result, problem[idx]);
    }
    return result;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    // 필요한 최대 알고력 & 코딩력 계산
    int maxAlp = maxAbility(problems, 0);
    int maxCop = maxAbility(problems, 1);
    
    // dp 테이블: dp[alp][cop] = alp, cop를 얻는 최단 시간
    vector<vector<int>> dp(maxAlp + 1, vector<int>(maxCop + 1, INT_MAX));
    
    // 초기 세팅
    alp = min(alp, maxAlp);
    cop = min(cop, maxCop);
    dp[alp][cop] = 0;
    
    // dp 테이블 채우기
    for(int a = alp; a <= maxAlp; a++){
        for(int c = cop; c <= maxCop; c++){
            if(dp[a][c] == INT_MAX){
                continue;
            }
            
            // 풀 수 있는 문제 모두 풀기
            for(vector<int> problem : problems){
                if(a < problem[0] || c < problem[1]){
                    continue;
                }
                
                int nextAlp = min(maxAlp, a + problem[2]);
                int nextCop = min(maxCop, c + problem[3]);
                dp[nextAlp][nextCop] = min(dp[nextAlp][nextCop], dp[a][c] + problem[4]);
            }
    
            // 알고력 키우기
            if(a + 1 <= maxAlp){
                dp[a + 1][c] = min(dp[a + 1][c], dp[a][c] + 1);
            }
            
            // 코딩력 키우기
            if(c + 1 <= maxCop){
                dp[a][c + 1] = min(dp[a][c + 1], dp[a][c] + 1);
            }
        }
    }
    
    return dp[maxAlp][maxCop];
}