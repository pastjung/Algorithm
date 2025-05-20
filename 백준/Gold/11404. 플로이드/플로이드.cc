#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX / 2;

void floydWarshall(vector<vector<int>>& graph){
    int n = graph.size() - 1;

    for(int k = 1; k <= n; k++){
        for(int to = 1; to <= n; to++){
            for(int from = 1; from <= n; from++){
                graph[to][from] = min(graph[to][from], graph[to][k] + graph[k][from]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 데이터 입력
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));

    for(int n = 1; n <= N; n++){
        graph[n][n] = 0;
    }
    
    for(int m = 0; m < M; m++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    // 최소 비용 계산
    floydWarshall(graph);

    // 결과 출력
    for (int to = 1; to <= N; to++) {
        for (int from = 1; from <= N; from++) {
            if (graph[to][from] == INF) {
                cout << 0 << ' ';
            } else {
                cout << graph[to][from] << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}