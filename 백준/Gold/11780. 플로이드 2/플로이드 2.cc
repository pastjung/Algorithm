#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX / 2;

void floydWarshall(vector<vector<int>>& graph, vector<vector<int>>& middle){
    int n = graph.size() - 1;

    for(int k = 1; k <= n; k++){
        for(int to = 1; to <= n; to++){
            for(int from = 1; from <= n; from++){
                if(graph[to][k] + graph[k][from] < graph[to][from]){
                    // 최소 비용 갱신
                    graph[to][from] = min(graph[to][from], graph[to][k] + graph[k][from]);
    
                    // 중간 경로 갱신
                    middle[to][from] = k;
                }
            }
        }
    }
}

void getPath(int to, int from, const vector<vector<int>>& middle, vector<int>& path){
    if(middle[to][from] == 0) return;

    int k = middle[to][from];
    getPath(to, k, middle, path);
    path.push_back(k);
    getPath(k, from, middle, path);
}

void print(int N, vector<vector<int>>& graph, vector<vector<int>>& middle){
    // 최소 비용 출력
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

    // 중간 경로 출력
    for(int to = 1; to <= N; to++){
        for(int from = 1; from <= N; from++){
            if (graph[to][from] == INF || to == from) {
                cout << 0 << '\n';
                continue;
            }

            // 중간 경로 복원
            vector<int> path;
            path.push_back(to);
            getPath(to, from, middle, path);
            path.push_back(from);

            // 중간 경로 출력
            cout << path.size() << ' ';
            for(int k : path){
                cout << k << ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 데이터 입력
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));   // i -> j의 최소 비용
    vector<vector<int>> middle(N + 1, vector<int>(N + 1, 0));    // i -> j의 중간 노드 ( 중간에 거쳐가는 노드 저장 )

    for(int n = 1; n <= N; n++){
        graph[n][n] = 0;
    }
    
    for(int m = 0; m < M; m++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    // 최소 비용 계산
    floydWarshall(graph, middle);

    // 결과 출력
    print(N, graph, middle);
    
    return 0;
}