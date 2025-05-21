#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

bool bellmanFord(int start, int N, vector<tuple<int, int, int>>& edges){
    vector<int> dist(N + 1, INT_MAX);
    dist[start] = 0;

    // (N - 1)번 모든 간선 확인
    for(int i = 1; i <= N; i++){
        for(auto [u, v, w] : edges){
            if(dist[u] != INT_MAX && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
            }
        }
    }

    // 음수 사이클 확인
    for(auto [u, v, w] : edges){
        if(dist[u] != INT_MAX && dist[v] > dist[u] + w){
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;  // 테스트케이스
    cin >> T;
    for(int t = 1; t <= T; t++){        
        int N, M, W;  // 지점, 도로, 웜홀
        cin >> N >> M >> W;

        vector<tuple<int, int, int>> edges;

        // 도로: 양방향
        for(int m = 0; m < M; m++){
            int S, E, T;  // 도로의 정보 : S-E, T시간
            cin >> S >> E >> T;
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }

        // 웜홀: 단방향, 음수
        for(int w = 0; w < W; w++){
            int S, E, T;  // 웜홀 정보 : S->E, 줄어드는 T시간
            cin >> S >> E >> T;
            edges.push_back({S, E, -T});
        }

        // 가상의 정점 0 → 모든 노드에 0 비용 간선 추가
        for (int i = 1; i <= N; i++) {
            edges.push_back({0, i, 0});
        }

        if(bellmanFord(0, N, edges)){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    
    return 0;
}