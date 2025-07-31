#include<vector>
#include<queue>
using namespace std;

// 방향 벡터
vector<int> dy = {0, 1, 0, -1};
vector<int> dx = {1, 0, -1, 0};

// bfs
int bfs(vector<vector<int>>& maps, pair<int, int> start, pair<int, int> end){
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));  // 방문한 노드를 기록할 배열
    queue<pair<int, int>> q;                            // 인접 노드를 기록할 큐
    
    // 초기 세팅
    visited[start.second][start.first] = 1;
    q.push(start);
    
    // 큐를 확인하면서 인접 최단 거리 계산
    while(!q.empty()){
        // 큐의 front 확인
        auto [x, y] = q.front();
        q.pop();
        
        // 현재 위치가 상대 진형인 경우
        if(x == end.first && y == end.second){
            return visited[y][x];
        }
        
        // 인접 노드 확인
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(0 <= ny && ny < n && 0 <= nx && nx < m && maps[ny][nx] == 1){
                if(visited[ny][nx] == 0){
                    q.push({nx, ny});
                    visited[ny][nx] = visited[y][x] + 1;
                } else{
                    visited[ny][nx] = min(visited[ny][nx], visited[y][x] + 1);    
                }
            }
        }
    }
    
    // 상대 진형을 가지 못하는 경우
    return -1;
}

int solution(vector<vector<int>> maps){
    pair<int, int> start = {0, 0};                               // 시작 좌표
    pair<int, int> end = {maps[0].size() - 1, maps.size() -1};   // 목표 좌표
    
    // 최단 거리 계산 : bfs
    return bfs(maps, start, end);
}