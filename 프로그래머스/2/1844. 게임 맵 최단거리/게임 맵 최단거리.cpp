#include<vector>
#include<queue>
using namespace std;

// 아래, 오른쪽, 위쪽, 왼쪽
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// BFS를 활용한 방법
int solution(vector<vector<int>> maps) {
    int n = maps.size();       // 행(row) 개수
    int m = maps[0].size();    // 열(column) 개수
    queue<vector<int>> q;      // { x, y, length }
    q.push({0, 0, 1});
    
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int length = q.front()[2];
        q.pop();
        
        // 목적지 도착하면 경로 길이 반환
        if (x == n - 1 && y == m - 1) return length;
        
        maps[x][y] = 0;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i]; 
            
            // 맵의 범위를 벗어나지 않고, 이동 가능할 때
            if (0 <= nx && nx < n && 0 <= ny && ny < m && maps[nx][ny] == 1) {
                maps[nx][ny] = 0;  // 방문 표시 (중복 방지)
                q.push({nx, ny, length + 1});
            }
        }
    }
    
    return -1; // 도달 불가능하면 -1 반환
}