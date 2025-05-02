#include <string>
#include <vector>
#include <queue>

using namespace std;

void DFS(vector<vector<int>> &graph, vector<bool> &visited, int start){
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        
        int idx = -1;
        for(int neighbor : graph[currentNode]){
            idx++;
            if(neighbor && !visited[idx]){
                visited[idx] = true;
                q.push(idx);
            }
        }   
    }    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            answer++;
            DFS(computers, visited, i);
        }
    }
    return answer;
}