#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int BFS(int n, vector<vector<int>>& edges){
    vector<int> depth(n + 1, -1);
    queue<int> q;
    
    depth[1] = 0;
    q.push(1);
    
    while(!q.empty()){        
        int cur = q.front();
        q.pop();
        
        for(int next : edges[cur]){
            if(depth[next] == -1){
                depth[next] = depth[cur] + 1;
                q.push(next);
            }
        }
    }
    
    int maxDepth = *max_element(depth.begin() + 1, depth.end());
    return count(depth.begin() + 1, depth.end(), maxDepth);
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> edges(n + 1, vector<int>());
    
    for(vector<int> e : edge){
        edges[e[0]].push_back(e[1]);
        edges[e[1]].push_back(e[0]);
    }
    
    return BFS(n, edges);
}