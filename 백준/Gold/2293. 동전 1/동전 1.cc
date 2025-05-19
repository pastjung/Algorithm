#include <iostream>
#include <vector>
#include <algorithm>
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

    vector<int> dp(K + 1, 0);
    dp[0] = 1;

    for(int coin : coins){
        for(int k = coin; k <= K; k++){
            dp[k] += dp[k - coin];
        }
    }

    cout << dp[K] << '\n';
    return 0;
}