#include <string>
#include <vector>

using namespace std;

/*
예시
2번은 1, 3, 4에게 지고, 5번을 이기므로 n-1개의 경기가 주어져서 확실히 순위를 정할 수 있음
5번은 2번한테 지는 데, 2번이 1, 3, 4한테 지므로 5번도 1, 3, 4한테 짐 -> 즉, 5번은 1, 2, 3, 4 모두에게 짐
*/

int DFS(vector<vector<int>>& graph, vector<bool>& visited, int start){
    visited[start] = true;
    int count = 0;
    for(int next : graph[start]){
        if(!visited[next]) count += 1 + DFS(graph, visited, next);
    }
    return count;
}

/*
문제 풀이 핵심
- 1~n을 각각을 기준으로 win / lose 양방향으로 DFS 탐색
- 위 / 아래 방향으로 각각 DFS를 수행한 값의 합이 n-1이면 정확한 순위 판단 가능 -> 정답
*/
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> win(n + 1);
    vector<vector<int>> lose(n + 1);
    
    for(vector<int> edge : results){
        win[edge[0]].push_back(edge[1]);
        lose[edge[1]].push_back(edge[0]);
    }
    
    for(int i = 1; i <= n; i++){
        vector<bool> w_visited(n + 1, false);
        vector<bool> l_visited(n + 1, false);
        int play = DFS(win, w_visited, i) + DFS(lose, l_visited, i);
        if(play == n - 1) answer++;
    }
    
    return answer;
}