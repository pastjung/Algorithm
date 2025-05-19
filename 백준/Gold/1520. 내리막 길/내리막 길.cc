#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int M, N;
vector<vector<int>> board;
vector<vector<int>> dp;

int dfs(int y, int x){
    if(y == M - 1 && x == N - 1) return 1;
    if(dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= ny && ny < M && 0 <= nx && nx < N){
            if(board[ny][nx] < board[y][x]){
                dp[y][x] += dfs(ny, nx);
            }
        }
    }
    return dp[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> M >> N;
    board.resize(M, vector<int>(N));
    dp.resize(M, vector<int>(N, -1));
    
    for(int m = 0; m < M; m++){
        for(int n = 0; n < N; n++){
            cin >> board[m][n];
        }
    }
    
    cout << dfs(0, 0) << '\n';
    return 0;
}