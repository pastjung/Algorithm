#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int answer = INT_MAX;
int N, M;

vector<vector<int>> board;
vector<pair<int, int>> cctv;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<vector<vector<int>>> dirs = {
    {},                                            // 0번 CCTV 없음
    {{0}, {1}, {2}, {3}},                          // 1번: 한 방향
    {{0, 2}, {1, 3}},                              // 2번: 두 방향 (상하, 좌우)
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},              // 3번: ㄴ자
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},  // 4번: 3방향
    {{0, 1, 2, 3}}                                 // 5번: 4방향 전부
};

void watch(vector<vector<int>>& board, int y, int x, int dir){
    while(true){
        y += dy[dir];
        x += dx[dir];
        
        if (y < 0 || y >= N || x < 0 || x >= M || board[y][x] == 6) break;
        if(board[y][x] == 0){
            board[y][x] = -1;
        }
    }
}

void dfs(int idx){
    if(cctv.size() == idx){
        int zero = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(board[i][j] == 0) zero++;
            }
        }
        answer = min(answer, zero);
        return;
    }

    auto[y, x] = cctv[idx];
    int cctvType = board[y][x];

    for(vector<int> dirSet : dirs[cctvType]){
        vector<vector<int>> tempBoard = board;
        int reduced = 0;
        
        // 선택
        for(int dir : dirSet){
            watch (tempBoard, y, x, dir);
        }

        // 원본 board를 temp로 대체하고 다음 재귀 호출
        swap(board, tempBoard);
        dfs(idx + 1);
        swap(board, tempBoard);  // 원복 (백트래킹)  
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N);
    for(int n = 0; n < N; n++){
        for(int m = 0; m < M; m++){
            int temp;
            cin >> temp;
            board[n].push_back(temp);

            if(1 <= temp && temp <= 5){
                cctv.push_back({n, m});
            }
        }   
    }

    dfs(0);
    cout << answer << '\n';
    return 0;
}