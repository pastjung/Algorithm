#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int dijkstra(int start, int end, vector<vector<pair<int,int>>>& bus){
    int n = bus.size();
    vector<int> distance(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        auto[dist, now] = pq.top();
        pq.pop();

        if(dist > distance[now]) continue;

        for(const auto& [s, d] : bus[now]){
            int cost = dist + d;
            if(cost < distance[s]){
                distance[s] = cost;
                pq.push({cost, s});
            }
        }
    }
    return distance[end];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> bus(N + 1);
    for(int m = 0; m < M; m++){
        int to, from, cost;
        cin >> to >> from >> cost;
        bus[to].push_back({from, cost});
    }

    int start, end;
    cin >> start >> end;
    cout << dijkstra(start, end, bus) << '\n';
    return 0;
}