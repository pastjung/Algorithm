#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
풀이 방법
- 방향 벡터를 사용
- 2배 좌표계를 사용해 사각형을 vector<bool>에 채우고, 내부는 비우기 ( 2배 좌표계를 사용했기 때문에 결과는 절반값 )
- 이후 BFS 수행
*/

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    const int SIZE = 102;
    bool map[SIZE][SIZE] = {false};       // 2배 좌표계 - 꼭짓점 구분을 위해 2배로 설정
    bool visited[SIZE][SIZE] = {false};
    
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    
    // 2배로 좌표 확장
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    // 사각형 채우기
    for(vector<int> rect : rectangle){
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;
        
        for(int y = y1; y <= y2; y++){
            for(int x = x1; x <= x2; x++){
                map[y][x] =  true;
            }
        }
    }
    
    // 사각형 내부 제거 ( 겹치는 부분 포함 제거 )
    for(vector<int> rect : rectangle){
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;
        
        for(int y = y1 + 1; y < y2; y++){
            for(int x = x1 + 1; x < x2; x++){
                map[y][x] =  false;
            }
        }
    }
    
    
    // BFS로 최단 경로 찾기
    queue<pair<int, int>> q;
    queue<int> dist;
    
    // 초기 설정
    q.push({characterX, characterY});
    dist.push(0);
    visited[characterY][characterX] = true;
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        int d = dist.front();
        dist.pop();
        
        if(x == itemX && y == itemY) return d / 2;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE) continue;
            if(!map[ny][nx] || visited[ny][nx]) continue;
            
            visited[ny][nx] = true;
            q.push({nx, ny});
            dist.push(d + 1);
        }
    }
    
    return -1;  // 도달 불가능한 경우
}