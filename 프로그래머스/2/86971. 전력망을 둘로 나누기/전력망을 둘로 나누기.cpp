#include <string>
#include <vector>
using namespace std;

// dfs 함수
int dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& count, int node){
    // 현재 노드를 방문한 목록과 방문한 경로 추가
    visited[node] = true;
    int subTreeSize = 1;

    // 현재 노드와 인접한 노드 중, 방문하지 않은 노드에 dfs 계속 진행
    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            subTreeSize += dfs(graph, visited, count, neighbor);
        }
    }
    
    count[node] = subTreeSize;
    return subTreeSize;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    vector<vector<int>> graph(n);     // 인접 리스트
    vector<bool> visited(n, false);   // 방문 여부를 저장할 배열
    vector<int> count(n, 0);          // 하위 노드의 개수를 저장할 배열
    
    // 인접 리스트 초기화
    for(vector<int> wire : wires){
        int u = wire[0] - 1;
        int v = wire[1] - 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // dfs를 통해 하위 노드의 개수 계산
    dfs(graph, visited, count, 0);
    
    // 하위 노드의 개수 / 2가 가장 낮은 수 계산
    for(int num : count){
        answer = min(abs(n - 2 * num), answer);
    }

    return answer;
}