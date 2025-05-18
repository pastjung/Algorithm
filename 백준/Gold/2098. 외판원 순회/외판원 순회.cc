#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
vector<vector<int>> city;

int minCost(vector<vector<int>>& dp){
    int answer = INT_MAX;
    for(int last = 0; last < N; last++){
        if(city[last][0] != 0 && dp[last][(1 << N) - 1] != INT_MAX){
            answer = min(answer, dp[last][(1 << N) - 1] + city[last][0]);
        }
    }
    return answer;
}

int DP(vector<vector<int>> city, int N){
    vector<vector<int>> dp(N, vector<int>((1 << N), INT_MAX));

    // 0번 도시 방문
    dp[0][1 << 0] = 0;

    for(int visited = 0; visited < (1 << N); visited++){
        for(int cur = 0; cur < N; cur++){
            if(dp[cur][visited] == INT_MAX) continue;  // 갈 수 없는 경우
            for(int next = 0; next < N; next++){
                if((visited & (1 << next)) == 0 && city[cur][next] != 0){
                    int nextVisited = visited | ( 1 << next);
                    dp[next][nextVisited] = min(dp[next][nextVisited], dp[cur][visited] + city[cur][next]);
                }
            }
        }
    }

    return minCost(dp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    city.resize(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> city[i][j];
        }
    }

    cout << DP(city, N) << '\n';
    return 0;
}