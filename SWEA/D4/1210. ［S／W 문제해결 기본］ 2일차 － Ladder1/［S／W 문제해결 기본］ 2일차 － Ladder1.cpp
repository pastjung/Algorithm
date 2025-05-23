#include <iostream>
#include <vector>
using namespace std;

int ladder(int y, int x, vector<vector<int>>& board) {
    while (y > 0) {
        board[y][x] = 0;

        if (x > 0 && board[y][x - 1] == 1) {
            while (x > 0 && board[y][x - 1] == 1) {
                x--;
                board[y][x] = 0;
            }
        } else if (x < 99 && board[y][x + 1] == 1) {
            while (x < 99 && board[y][x + 1] == 1) {
                x++;
                board[y][x] = 0;
            }
        }

        y--;
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int t = 1; t <= 10; t++) {
        int test_case_number;
        cin >> test_case_number;

        vector<vector<int>> board(100, vector<int>(100));
        int start = 0;

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> board[i][j];
                if (board[i][j] == 2) {
                    start = j;
                }
            }
        }

        cout << '#' << test_case_number << ' ' << ladder(99, start, board) << '\n';
    }

    return 0;
}
