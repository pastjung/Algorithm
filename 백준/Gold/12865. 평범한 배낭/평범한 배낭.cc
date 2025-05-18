#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> things(N);
    for(int n = 0; n < N; n++){
        cin >> things[n].first >> things[n].second;
    }
    
    vector<int> dp(K + 1, 0);  // 무게 k일 때 얻을 수 있는 최대 가치
    for(auto [w, v] : things){
        for(int k = K; k >= w; k--){
            dp[k] = max(dp[k], dp[k -w] + v);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
    return 0;
}