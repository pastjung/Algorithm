#include <vector>
using namespace std;

int top_down(int n, vector<int>& dp){
    if(dp[n] != -1){
        return dp[n];
    }
    
    dp[n] = (top_down(n - 1, dp) + top_down(n - 2, dp)) % 1000000007;
    return dp[n];
}

int solution(int n) {
    vector<int> dp(n + 1, -1);
    dp[1] = 1;
    dp[2] = 2;
    return top_down(n, dp);
}