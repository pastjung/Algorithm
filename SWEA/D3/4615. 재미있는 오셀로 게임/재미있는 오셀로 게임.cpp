#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void func(vector<vector<int>>& board, int x, int y, int stone, int N, int dx, int dy){
    int nx = x, ny = y, count = 0;
    while(1 <= nx && nx <= N && 1 <= ny && ny <= N){
     	nx += dx;
        ny += dy;
        count++;
        if (board[ny][nx] == 0) break;
        if(board[ny][nx] == stone){
         	for(int i = 1; i < count; i++) board[y + dy * i][x + dx * i] = stone;
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N, M;
        cin >> N >> M;
        vector<vector<int>> board(N+2, vector<int>(N+2, 0));
        
        // 초기 세팅
        board[N/2][N/2] = 2;
        board[N/2 + 1][N/2 + 1] = 2;
        board[N/2 + 1][N/2] = 1;
        board[N/2][N/2 + 1] = 1;
        
        for(int j = 1; j <= M; j++){
            int x, y, stone;
            cin >> x >> y >> stone;
            board[y][x] = stone;
            
            // 상하좌우 탐색
            func(board, x, y, stone, N, -1, 0);
            func(board, x, y, stone, N, 1, 0);
            func(board, x, y, stone, N, 0, -1);
            func(board, x, y, stone, N, 0, 1);

            // 대각선 탐색
            func(board, x, y, stone, N, -1, -1);
            func(board, x, y, stone, N, 1, 1);
            func(board, x, y, stone, N, -1, +1);
            func(board, x, y, stone, N, 1, -1);
        }
        
        int black = 0, white = 0;
        for(int x = 1; x <= N; x++){
            for(int y = 1; y <= N; y++){
                if(board[y][x] == 1) black++;
                else if(board[y][x] == 2) white++;
            }
        }
        cout << '#' << i << ' ' << black << ' ' << white << '\n';
    }
    return 0;
}