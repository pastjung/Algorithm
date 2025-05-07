#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cal(const vector<int>& money){
    int n = money.size();
    vector<int> dp(n, 0);
    
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + money[i]);
    }
    
    return dp[n - 1];
}

int solution(vector<int> money) {
    vector<int> case1(money.begin(), money.end() - 1);  // Case 1 : 첫 번째 집을 털고 마지막 집은 못 털기 (money[0] ~ money[n-2])
    vector<int> case2(money.begin() + 1, money.end());  // Case 2 : 첫 번째 집을 안 털고 마지막 집을 털기 (money[1] ~ money[n-1])
    
    return max(cal(case1), cal(case2));
}