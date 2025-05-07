#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // 함정 세팅
    for(vector<int> puddle : puddles){
        int mm = puddle[0];
        int nn = puddle[1];
        dp[nn][mm] = -1;
    }
    
    // 가장자리 세팅
    for(int mm = 1; mm <= m; mm++){
        if(dp[1][mm] == -1) break;
        dp[1][mm] = 1;
    }
    for(int nn = 1; nn <= n; nn++){
        if(dp[nn][1] == -1) break;
        dp[nn][1] = 1;
    }
    
    // 내부 세팅 -> 위, 왼쪽 값 더하기
    for(int nn = 2; nn <= n; nn++){
        for(int mm = 2; mm <= m; mm++){    
            if(dp[nn][mm] != -1){
                int up = ( dp[nn - 1][mm] > 0 ? dp[nn - 1][mm] : 0);
                int left = ( dp[nn][mm - 1] > 0 ? dp[nn][mm - 1] : 0);
                dp[nn][mm] = ( up + left ) % 1000000007;
            }
        }
    }
    
    return dp[n][m];
}