#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[9][9];
vector<pair<int, int>> blanks;

void print(){
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool isValid(int x, int y, int num){
    // 행, 열 검사
    for (int i = 0; i < 9; i++) {
        if (board[y][i] == num || board[i][x] == num)
            return false;
    }

    // 3x3 박스 검사
    int sy = (y / 3) * 3;
    int sx = (x / 3) * 3;
    for (int i = sy; i < sy + 3; i++) {
        for (int j = sx; j < sx + 3; j++) {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

void dfs(int depth){
    if(depth == blanks.size()){
        print();
        exit(0);
    }

    int y = blanks[depth].first;
    int x = blanks[depth].second;

    for(int num = 1; num <= 9; num++){
        if(isValid(x, y, num)){
            board[y][x] = num;
            dfs(depth + 1);
            board[y][x] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                blanks.push_back({i, j});
            }
        }
    }

    dfs(0);
    return 0;
}