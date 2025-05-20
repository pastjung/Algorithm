#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int,int>>>& edges){
    int n = edges.size();
    vector<int> distance(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // {거리, 정점};

    distance[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        auto[dist, now] = pq.top();
        pq.pop();

        // 이미 처리된 정점이면 무시
        if(dist > distance[now]) continue;

        for(const auto& edge : edges[now]){
            int cost = dist + edge.second;
            if(cost < distance[edge.first]){
                distance[edge.first] = cost;
                pq.push({cost, edge.first});
            }
        }
    }
    return distance;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int V, E, K;
    cin >> V >> E >> K;
    
    vector<vector<pair<int,int>>> edges(V + 1);
    for(int e = 0; e < E; e++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }

    vector<int> answer = dijkstra(K, edges);
    for(int i = 1; i <= V; ++i){
        if(answer[i] == INT_MAX){
            cout << "INF\n";
        } else{
            cout << answer[i] << '\n';
        }
    }
    return 0;
}