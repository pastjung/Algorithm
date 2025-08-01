#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// 정보를 저장할 노드
struct Node {
    int x, y, cost, dir;
};

// 방향 벡터
vector<int> dy = {0, 1, 0, -1};
vector<int> dx = {1, 0, -1, 0};

// bfs
int solution(vector<vector<int>> board) {
    int n = board.size();
    
    // 방문 여부를 기록할 배열 - 방향별 방문 기록
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(n, vector<int>(4, INT_MAX)));   
    queue<Node> q;   // 인접 노드를 기록할 큐

    // 초기 세팅
    if(board[0][1] == 0){
        visited[0][1][0] = 100;
        q.push({1, 0, 100, 0});
    }
    if(board[1][0] == 0){
        visited[1][0][1] = 100;
        q.push({0, 1, 100, 1});
    }

    // 인접 노드 관리
    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++){
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            
            if(ny < 0 || nx < 0 || n <= ny || n <= nx) continue;
            if(board[ny][nx] == 1) continue;
            
            int newCost = cur.cost + (dir == cur.dir ? 100 : 600);
            
            if(visited[ny][nx][dir] > newCost){
                visited[ny][nx][dir] = newCost;
                q.push({nx, ny, newCost, dir});
            }
        }
    }
    
    return *min_element(visited[n - 1][n - 1].begin(), visited[n - 1][n - 1].end());
}