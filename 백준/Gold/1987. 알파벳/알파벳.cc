#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
int answer = 0;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<vector<char>> board;
vector<bool> used(26, false);

void dfs(int x, int y, int count){
    answer = max(answer, count);

    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 범위 체크
        if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
            int alpha = board[ny][nx] - 'A';
            if (!used[alpha]) {
                used[alpha] = true;
                dfs(nx, ny, count + 1);
                used[alpha] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    board.resize(R, vector<char>(C));
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cin >> board[r][c];
        }
    }

    used[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << answer << '\n';
    return 0;
}