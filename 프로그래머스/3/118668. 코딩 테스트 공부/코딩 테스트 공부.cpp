#include <string>
#include <vector>
#include <climits>
using namespace std;

/* 문제 분석
- 문제 설명
    - 문제가 요구하는 일정 이상의 알고력과 코딩력 필요
    - 각 능력을 1 높이기 위해서는 1의 시간이 필요
    - 현재 풀 수 있는 문제를 풀면 알고력과 코딩력이 상승
    - 문제를 하나 푸는 데는 문제가 요구하는 시간이 필요
    - 같은 문제를 여러 번 푸는 것 가능
    - 주어진 모든 문제를 풀 수 있는 알고력과 코딩력을 얻는 최단시간 구하기
    - 모든 문제들을 1번 이상씩 풀 필요 X
- 입력 데이터
    - 초기 알고력 alp > 0
    - 초기 코딩력 cop > 0
    - 문제의 정보 problems : 최대 100개 -> O(N^4) 알고리즘 사용 가능
        - [필요한 알고력, 필요한 코딩력, 증가하는 알고력, 증가하는 코딩력, 푸는 시간]
- 핵심 키워드
    - 능력을 키우기 위한 방법은 2가지
        1. 1의 시간을 사용해서 1개의 능력치를 1상승
        2. 문제를 해결하여 능력 상승
*/

int solution(int alp, int cop, vector<vector<int>> problems) {
    int max_alp = 0, max_cop = 0;   // alp와 cop의 최대 값
    
    for(vector<int> problem : problems){
        max_alp = max(max_alp, problem[0]);
        max_cop = max(max_cop, problem[1]);
    }
    
    // dp[alp][cop] 테이블 -> 사용 시간이 적은 값 저장
    vector<vector<int>> dp(max_alp + 1, vector<int>(max_cop + 1, INT_MAX));
    
    // dp 테이블 초기 세팅 : 초기 alp와 cop 설정
    alp = min(alp, max_alp);
    cop = min(cop, max_cop);
    dp[alp][cop] = 0;
    
    // dp 테이블 채우기 -> 만약 max_alp와 max_cop를 넘기는 경우 min을 사용해 최대치에 저장
    for(int i = alp; i <= max_alp; i++){
        for(int j = cop; j <= max_cop; j++){
            if (dp[i][j] == INT_MAX) continue;
            
            // 현재 alp와 cop을 사용해서 풀 수 있는 모든 문제 풀기
            for(vector<int> problem : problems){
                if(i >= problem[0] && j >= problem[1]){
                    int ni = min(i + problem[2], max_alp);
                    int nj = min(j + problem[3], max_cop);
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + problem[4]);
                }
            }
            
            // 알고력을 1 증가시킨 경우
            if(i + 1 <= max_alp){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);    
            }
            
            // 코딩력을 1 증가시킨 경우
            if(j + 1 <= max_cop){
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);   
            }
        }
    }
        
    return dp[max_alp][max_cop];
}