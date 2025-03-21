#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void DFS(const vector<vector<int>> &graph, vector<bool> &visited, int node){
    // 초기 세팅
    visited[node] = true;
    cout << node << ' ';

    // DFS
    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            DFS(graph, visited, neighbor);
        }
    }
}

void BFS(const vector<vector<int>> &graph, int start){
    vector<bool> visited(graph.size());
    queue<int> q;

    // 초기 세팅
    visited[start] = true;
    q.push(start);    
    cout << start << ' ';

    // BFS
    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        
        for(int neighbor : graph[currentNode]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                cout << neighbor << ' ';
                q.push(neighbor);
            } 
        }
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, V;
    
    cin >> N >> M >> V;
    vector<vector<int>> graph(N+1);

    for(int m = 0; m < M; m++){
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    for(int i = 1; i <= N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> visited(graph.size(), false);
    DFS(graph, visited, V);
    cout << '\n';
    BFS(graph, V);

    return 0;
}