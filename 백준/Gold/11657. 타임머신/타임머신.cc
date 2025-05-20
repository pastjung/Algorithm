#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

bool bellmanFord(int start, int N, vector<tuple<int, int, int>> &edges, vector<long long>& dist){
    dist[start] = 0;

    // (n - 1)번 모든 간선 확인
    for(int n = 0; n < N- 1; n++){
        for(auto [from, to, weight] : edges){
            if(dist[from] != LLONG_MAX && dist[from] + weight < dist[to]){
                dist[to] = dist[from] + weight;
            }
        }
    }

    // 음수 사이클 확인
    for(auto [from, to, weight] : edges){
        if(dist[from] != LLONG_MAX && dist[from] + weight < dist[to]){
            return false;
        }
    }
    
    return true;
}

void print(int N, vector<long long> dist){
    for(int n = 2; n <= N; n++){
        if(dist[n] == LLONG_MAX){
            cout << "-1\n";
        } else{
            cout << dist[n] << '\n';   
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> edges;
    vector<long long> dist(N + 1, LLONG_MAX);

    for(int m = 0; m < M; m++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    if(!bellmanFord(1, N, edges, dist)){
        cout << "-1\n";
    } else {
        print(N, dist);
    }
    
    return 0;
}