#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

// wires를 for문으로 해서 반복 -> 해당 지점에서 해당 wire제거
// 1번부터 연결된 개수 파악 -> DFS ( visited 활용 )
// 파악한 개수 x -> | 2x - n | 의 최솟값 반환

// DFS로 연결된 노드 개수 계산
int dfs(int node, vector<vector<int>> connect, vector<bool>& visited) {
    visited[node] = true;
    int count = 1;

    for (int neighbor : connect[node]) {
        if (!visited[neighbor]) {
            count += dfs(neighbor, connect, visited);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    vector<vector<int>> connect(n + 1);
    for(vector<int> wire : wires){
        connect[wire[0]].push_back(wire[1]);
        connect[wire[1]].push_back(wire[0]);
    }
    
    for(vector<int> wire : wires){
        
        // 간선 제거
        connect[wire[0]].erase(remove(connect[wire[0]].begin(), connect[wire[0]].end(), wire[1]), connect[wire[0]].end());
        connect[wire[1]].erase(remove(connect[wire[1]].begin(), connect[wire[1]].end(), wire[0]), connect[wire[1]].end());

        // 그룹 크기 계산
        vector<bool> visited(n + 1, false);
        int group1 = dfs(1, connect, visited);
        int group2 = n - group1;
        
        // 최소 차이 갱신
        answer = min(answer, abs(group1 - group2));
        
        // 간선 복구
        connect[wire[0]].push_back(wire[1]);
        connect[wire[1]].push_back(wire[0]);
    }  
    
    return answer;
}