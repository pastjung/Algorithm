#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

void dfs(int x, int y, int cnt, string str, vector<vector<char>>& board, set<string>& nums){
    if (x < 0 || x >= 4 || y < 0 || y >= 4) return;

    str += board[y][x];
    if(cnt == 6){
        nums.insert(str);
        return;
    }

    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        dfs(nx, ny, cnt + 1, str, board, nums);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        vector<vector<char>> board(4, vector<char>(4, 0));
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cin >> board[i][j];
            }
        }

        set<string> nums;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                dfs(j, i, 0, "", board, nums);
            }
        }
        cout << '#' << t << ' ' << nums.size() << '\n';
    }
    
    return 0;
}