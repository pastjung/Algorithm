#include <string>
#include <vector>
#include <queue>
using namespace std;

// 방향 벡터
vector<int> dy = {0, 1, 0, -1};
vector<int> dx = {1, 0, -1, 0};

// bfs 선언
int bfs(const vector<string>& maps, pair<int, int> start, pair<int, int> end){
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));   // 방문한 노드를 기록할 배열
    queue<pair<int, int>> q;                             // 인접 노드를 기록할 큐

    // 초기 설정
    visited[start.second][start.first] = 1;
    q.push(start);

    // 큐를 확인하면서 최단 거리 확인
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        if(x == end.first && y == end.second){
            return visited[y][x] - 1;
        }
        
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(0 <= ny && ny < n && 0 <= nx && nx < m && maps[ny][nx] != 'X' && visited[ny][nx] == 0){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    // 시작 지점, 레버, 통로 위치 확인
    pair<int, int> start, lever, end;
    for(int y = 0; y < maps.size(); y++){
        for(int x = 0; x < maps[y].size(); x++){
            if(maps[y][x] == 'S'){
                start = {x, y};
            } else if(maps[y][x] == 'L'){
                lever = {x, y};
            } else if(maps[y][x] == 'E'){
                end = {x, y};
            }
        }
    }
    
    // 시작 지점 ~ 레버 위치까지의 거리 계산
    int distance1 = bfs(maps, start, lever);
    if(distance1 == -1){
        return -1;
    }
    
    // 레버 위치 ~ 통로 위치까지의 거리 계산
    int distance2 = bfs(maps, lever, end);
    if(distance2 == -1){
        return -1;
    }
    
    return distance1 + distance2;
}