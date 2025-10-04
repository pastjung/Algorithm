#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <algorithm>
using namespace std;

int SIZE;
const int STARTX = 0;
const int STARTY = 0;
int ENDX;
int ENDY;

// 방향 벡터 -> 상좌우하
vector<int> dx = {0, -1, 1, 0};
vector<int> dy = {1, 0, 0, -1};

// 유망 함수 : 범위 확인
bool promising(const vector<vector<int>>& board, int x, int y){
    return STARTX <= x && x <= ENDX && STARTY <= y && y <= ENDY && board[y][x] != 1;
}

// BFS -> board에 비용 저장
int BFS(vector<vector<int>> board){
    queue<tuple<int, int, int>> q;    // 방문한 노드를 저장할 큐 (x, y, dir)
    vector<vector<vector<int>>> cost(SIZE, vector<vector<int>>(SIZE, vector<int>(4, INT_MAX)));

    // 초기 세팅
    q.push({STARTX, STARTY, -1});
    for(int d = 0; d < 4; d++){
        cost[STARTY][STARTX][d] = 0;
    }
    
    // 인근 노드 중 방문할 노드가 있는지 확인 (기존 방향, 좌우 방향 확인)
    while(!q.empty()){
        auto[x, y, dir] = q.front();
        q.pop();
        
        for(int ndir = 0; ndir < 4; ndir++){
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            
            if(!promising(board, nx, ny)){
                continue;
            }
            
            int preCost = (dir == -1) ? 0 : cost[y][x][dir];
            int newCost = preCost + ((dir == -1 || dir == ndir) ? 100 : 600);
            
            if(newCost < cost[ny][nx][ndir]){
                cost[ny][nx][ndir] = newCost;
                q.push({nx, ny, ndir});
            }
        }
    }
    
    return *min_element(cost[ENDY][ENDX].begin(), cost[ENDY][ENDX].end());
}

int solution(vector<vector<int>> board) {
    // 전역 변수 초기화
    SIZE = board.size();
    ENDX = SIZE - 1;
    ENDY = SIZE - 1;
    
    // BFS 초기화
    return BFS(board);
}