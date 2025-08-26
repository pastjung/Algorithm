#include <vector>
using namespace std;

// top-down 방식의 dp 구현
int top_down(int n, vector<int>& dp){
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = (top_down(n - 1 ,dp) + top_down(n - 2 ,dp)) % 1234567; 
    return dp[n];
}

int solution(int n) {
    int answer = 0;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    
    answer = top_down(n, dp);
    return answer;
}