#include <vector>
#include <climits>
using namespace std;

// 방향벡터
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

// 결과 구조체
struct Result {
    bool win;   // 현재 플레이어가 이길 수 있는가?
    int cnt;    // 이동 횟수
};

// 백트래킹 함수 (board, aloc, bloc, turn)
Result dfs(vector<vector<int>>& board, vector<int> aloc, vector<int> bloc, bool turnA){
    // 현재 턴 플레이어 좌표 결정
    int y = turnA ? aloc[0] : bloc[0];
    int x = turnA ? aloc[1] : bloc[1];

    // 기저 조건 (현재 발판이 이미 사라진 경우 → 패배)
    if(board[y][x] == 0){
        return {false, 0};
    }

    // 다음 이동을 저장할 변수 준비
    bool canWin = false;
    int minWin = INT_MAX;
    int maxLose = 0;

    // 4방향 탐색
    for(int dir = 0; dir < 4; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        // 유망성 검사 (범위 안, 발판 존재)
        if (ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size()) continue;
        if (board[ny][nx] == 0) continue;
        
        // 현재 칸을 없앰
        board[y][x] = 0;
        
        // 다음 좌표 갱신 (턴이 A면 aloc 갱신, B면 bloc 갱신)
        vector<int> nextA = aloc, nextB = bloc;
        if (turnA) nextA = {ny, nx};
        else nextB = {ny, nx};
        
        // 상대 턴으로 재귀
        Result next = dfs(board, nextA, nextB, !turnA);
        
       // 선택 취소
        board[y][x] = 1; 
        
        // 결과 판정
        if (!next.win) { // 상대가 패배한다면 → 현재는 승리
            canWin = true;
            minWin = min(minWin, next.cnt + 1);
        } else {         // 상대가 승리한다면 → 현재는 패배
            maxLose = max(maxLose, next.cnt + 1);
        }
    }

    if(canWin){
        return {true, minWin};
    } else{
        return {false, maxLose};
    }
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    return dfs(board, aloc, bloc, true).cnt;    // dfs 호출
}