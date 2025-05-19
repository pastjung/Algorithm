#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    
    vector<int> coins(N, 0);
    for(int n = 0; n < N; n++){
        cin >> coins[n];
    }

    vector<int> dp(K + 1, INT_MAX);
    dp[0] = 0;
    for(int coin : coins){
        for(int k = coin; k <= K; k++){
            if (dp[k - coin] != INT_MAX) {
                dp[k] = min(dp[k], dp[k - coin] + 1);
            }
        }
    }

    if(dp[K] == INT_MAX){
        cout << -1 << '\n';
    } else{
        cout << dp[K] << '\n';   
    }
    return 0;
}