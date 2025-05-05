#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
풀이 조건
- 조각은 한 번에 하나씩
- 조각 회전 가능
- 조각 뒤집기는 불가능
- 보드에 딱 맞게만 설치 가능
- 규칙에 맞게 최대한 많은 퍼즐 조각 채워 넣기 -> 총 몇칸?
- 퍼즐 조각 및 공간은 1 ~ 6조각으로 구성
*/

/*
풀이 방법
- 보드의 빈 공간과 테이블의 퍼즐 조각의 픽셀 수 파악 및 좌표 설정 -> 개수 배열에 추가
    - 방향 벡터와 BFS를 사용해 좌표 파악
- 쵀대한 많은 퍼즐을 넣을 수 있는지 파악
*/

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 좌표를 (0, 0) 기준으로 정규화 및 정렬
vector<pair<int, int>> normalize(vector<pair<int, int>> shape){
    int minX = 50, minY = 50;
    for(auto [x, y] : shape){
        minX = min(minX, x);
        minY = min(minY, y);
    }
    
    for(auto& [x, y] : shape){
        x -= minX;
        y -= minY;
    }
    
    sort(shape.begin(), shape.end());
    return shape;
}

// 도형을 90도 회전
vector<pair<int, int>> rotate(vector<pair<int, int>> shape) {
    for (auto& [x, y] : shape) {
        tie(x, y) = make_pair(y, -x);
    }
    return normalize(shape);
}

/*
target : 찾아야할 값
*/
vector<pair<int, int>> BFS(vector<vector<int>>& board, int x, int y, int target){
    vector<pair<int, int>> shape;
    queue<pair<int, int>> q;
    int bSize = board.size() - 1;
    
    // 초기 세팅
    board[y][x] = ( board[y][x] + 1 ) % 2;
    q.push({x, y});
    shape.push_back({x, y});
    
    // BFS 탐색
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if(nx < 0 || ny < 0 || nx > bSize || ny > bSize) continue;
            
            if(board[ny][nx] == target){
                board[ny][nx] = ( board[ny][nx] + 1 ) % 2;
                q.push({nx, ny});
                shape.push_back({nx, ny});
            }
        }
    }
    
    return normalize(shape);
}

/*
퍼즐 조각이 공간에 맞는지 확인
-> piece의 도형을 회전시키면서 space에 대입해서 맞는지 확인 -> 공간이 맞으면 count + 1
*/
bool check(vector<pair<int, int>> blank, vector<pair<int, int>> piece){
    for (int i = 0; i < 4; i++) {
        if (piece == blank) return true;
        piece = rotate(piece);
    }
    return false;
}

// 공간과 퍼즐 조각을 비교하여 최대한 채우기
int Match(const vector<vector<pair<int, int>>>& blanks, const vector<vector<pair<int, int>>>& pieces){
    int count = 0;
    
    vector<bool> used(pieces.size(), false);
    
    for(vector<pair<int, int>> blank : blanks){
        for(int i = 0; i < pieces.size(); i++){
            if(used[i]) continue;
            if(check(blank, pieces[i])){
                used[i] = true;
                count += pieces[i].size();
                break;
            }
        }
    }
    
    return count;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    vector<vector<pair<int, int>>> blanks, pieces;
    int size = table.size();
    
    // 빈 공간 찾기
    for(int y = 0; y < size; y++){
        for(int x = 0; x < size; x++){
            if(game_board[y][x] == 0){
                blanks.push_back(BFS(game_board, x, y, 0));
            }
        }
    }
    
    // 퍼즐 조각 찾기
    for(int y = 0; y < size; y++){
        for(int x = 0; x < size; x++){
            if(table[y][x] == 1){
                pieces.push_back(BFS(table, x, y, 1));
            }
        }
    }
    
    // 공간의 개수가 동일한 piece를 space에 넣을 수 있는지 파악
    return Match(blanks, pieces);
}