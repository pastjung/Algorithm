#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// bottom-up 함수
int bottom_up(const vector<vector<int>>& land){
    int n = land.size();
    vector<vector<int>> dp(land.begin(), land.end()); // dp 테이블
    
    // bottom-up 방식으로 모든 누적 합 계산
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int bestPrev = 0;
            for (int k = 0; k < 4; k++) {
                if (k == j){
                    continue; // 같은 열은 제외  
                } 
                bestPrev = max(bestPrev, dp[i - 1][k]);
            }
            dp[i][j] += bestPrev;
        }
    }
    
    // dp 테이블의 마지막 열 중 가장 큰 값 반환
    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}

int solution(vector<vector<int>> land) {
    return bottom_up(land);
}