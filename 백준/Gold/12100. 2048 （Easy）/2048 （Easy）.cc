#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int>> moveBoard(vector<vector<int>> board, int dir){
    int N = board.size();
    
    // 방향마다 다른 방식으로 행/열 처리
    for (int i = 0; i < N; i++) {
        vector<int> line;

        // 1. 값 추출 (방향에 따라 순서 달라짐)
        for (int j = 0; j < N; j++) {
            int val;
            if (dir == 0) val = board[j][i];               // 위
            else if (dir == 1) val = board[i][N - 1 - j];  // 오른쪽
            else if (dir == 2) val = board[N - 1 - j][i];  // 아래
            else val = board[i][j];                        // 왼쪽

            if (val != 0) line.push_back(val);
        }
        if(line.empty()) continue;

        // 2. 블록 합치기 (인덱스 기반)
        vector<int> merged;
        int idx = 0;
        while (idx < line.size()) {
            if (idx + 1 < line.size() && line[idx] == line[idx + 1]) {
                merged.push_back(line[idx] * 2);
                idx += 2; // 둘 다 사용했으므로 2칸 점프
            } else {
                merged.push_back(line[idx]);
                idx++;
            }
        }

        // 3. 나머지 0으로 채우기
        while (merged.size() < N) merged.push_back(0);

        // 4. 보드에 다시 삽입
        for(int j = 0; j < N; j++){
            if (dir == 0) board[j][i] = merged[j];
            else if (dir == 1) board[i][N - 1 - j] = merged[j];
            else if (dir == 2) board[N - 1 - j][i] = merged[j];
            else board[i][j] = merged[j];
        }
    }
    return board;
}

void dfs(int num, vector<vector<int>> board){
    if(num == 5){
        for(vector<int> b : board){
            answer = max(answer, *max_element(b.begin(), b.end()));
        }
        return;
    }

    // dfs 내용 수행
    for(int dir = 0; dir < 4; dir++){
        // 선택
        vector<vector<int>> nextBoard = moveBoard(board, dir);

        // 재귀
        dfs(num + 1, nextBoard);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    
    vector<vector<int>> board(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    
    dfs(0, board);
    cout << answer << '\n';
    return 0;
}