#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));  // k개의 정수를 사용해 n을 만드는 경우의 수
    for(int n = 0; n <= N; n++){
        dp[1][n] = 1;
    }

    for(int k = 2; k <= K; k++){
        for(int n = 0; n <= N; n++){
            for(int l = 0; l <= n; l++){
                dp[k][n] = (dp[k][n] + dp[k - 1][n - l]) % 1000000000;
            }
        }
    }
    cout << dp[K][N] << '\n';
    return 0;
}