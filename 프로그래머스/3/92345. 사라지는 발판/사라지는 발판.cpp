#include <string>
#include <vector>
#include <climits>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// 유망 함수: 범위 체크 & 발판 여부 체크
bool promising(const vector<vector<int>>& board, int x, int y){
    if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()){
        return false;
    }
    if(board[x][y] == 0){
        return false;
    }
    return true;
}


// 백트래킹(board, aloc, bloc, turn, answer)
pair<bool, int> backtracking(vector<vector<int>>& board, int ax, int ay, int bx, int by, bool turn){
    int x, y;
    if(turn == 0){
        x = ax, y = ay;
    } else{
        x = bx, y = by;
    }
    
    // 현재 칸이 없을 경우 -> 현재 턴 패비
    if(board[x][y] == 0){
        return {false, 0};
    }
    
    bool canWin = false;
    int minTurn = INT_MAX;      // 이기는 경우 최소 턴
    int maxTurn = 0;            // 지는 경우 최대 턴
    
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(!promising(board, nx, ny)){
            continue;
        }
        
        board[x][y] = 0;    // 현재 칸 제거
        
        pair<bool, int> result;
        if(turn == 0){
            result = backtracking(board, nx, ny, bx, by, 1);
        } else{
            result = backtracking(board, ax, ay, nx, ny, 0);
        }
        
        board[x][y] = 1;    // 원상 복구
        
        // 상대가 지는 경우 -> 나는 이김
        if(!result.first){
            canWin = true;
            minTurn = min(minTurn, result.second + 1);
        } else{
            maxTurn = max(maxTurn, result.second + 1);
        }
    }
    
    if(canWin){
        return {true, minTurn};
    } else{
        return {false, maxTurn};
    }
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    pair<bool, int> answer = backtracking(board, aloc[0], aloc[1], bloc[0], bloc[1], 0);
    return answer.second;
}