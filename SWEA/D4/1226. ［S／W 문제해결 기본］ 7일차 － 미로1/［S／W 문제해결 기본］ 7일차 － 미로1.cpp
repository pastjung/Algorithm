#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int SIZE = 16;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int bfs(vector<vector<char>> board, const pair<int, int>& start){
    queue<pair<int, int>> q;

    // 초기 세팅
    q.push(start);
    board[start.first][start.second] = '1';

    while(!q.empty()){
        auto[y, x] = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(0 <= nx && nx < SIZE && 0 <= ny && ny < SIZE){
                if(board[ny][nx] == '3'){
                    return 1;
                } else if(board[ny][nx] == '0'){
                    board[ny][nx] = '1';
                    q.push({ny, nx});    
                }
            }
        }
    }
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 10;
    for(int TC = 1; TC <= T; TC++){
        int t;
        cin >> t;
        vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));
        pair<int, int> start;
        for(int y = 0; y < SIZE; y++){
            for(int x = 0; x < SIZE; x++){
                cin >> board[y][x];
                if(board[y][x] == '2'){
                    start = {y, x};
                }
            }
        }
        
        cout << '#' << TC << ' ' << bfs(board, start) << '\n';
    }
    
    return 0;
}