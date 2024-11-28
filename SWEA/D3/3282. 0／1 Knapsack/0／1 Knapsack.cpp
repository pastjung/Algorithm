#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int DP(vector<int> V, vector<int> bag, int N, int K){
    vector<int> dp(K + 1, 0);  // dp[w]는 용량이 w일 때 얻을 수 있는 최대 가치
    
    // 각 아이템에 대해
    for (int i = 1; i <= N; i++) {
        // 아이템을 고려할 때, 용량 w를 뒤에서부터 탐색 (역순으로)
        // 역순으로 탐색하는 이유는 이미 dp[w - V[i]] 값을 갱신했기 때문에
        for (int w = K; w >= V[i]; w--) {
            dp[w] = max(dp[w], dp[w - V[i]] + bag[i]);
        }
    }
    
    return dp[K];  // 배낭의 용량이 K일 때 얻을 수 있는 최대 가치
}
	
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N, K;
        cin >> N >> K;
        vector<int> V(N + 1, 0);
        vector<int> bag(K + 1, 0);
        for(int n = 1; n <= N; n++){
         	   cin >> V[n] >> bag[n];
        }
        cout << '#' << i << ' ' << DP(V, bag, N, K) << '\n';
    }
    return 0;
}