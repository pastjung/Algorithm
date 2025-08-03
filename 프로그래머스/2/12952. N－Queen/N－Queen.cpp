#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 유망 함수 : 현재 (row, col)에 퀸을 놓을 수 있는지 확인
bool isPromising(vector<int>& board, int row, int col){
    for (int i = 0; i < row; i++) {
        // 같은 열 or 같은 대각선에 퀸이 있는 경우
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// 백트래킹
void backtracking(vector<int>& board, int& answer, int row){
    int n = board.size();
    
    // 기저 조건 : 모든 행에 퀸을 성공적으로 배치한 경우 ( 해답 1개 완성 )
    if(row == n){
        answer++;
        return;
    }

    // 다음 선택지 탐색 : 현재 행의 각 열에 대해 퀸을 놓을 수 있는지 검사
    for(int col = 0; col < n; col++){
        // 유망성 검사 : 세로 내 퀸 존재 X && 대각선 내 퀸 존재 X
        if(isPromising(board, row, col)){
            board[row] = col;
            backtracking(board, answer, row + 1);     // 다음 행으로 재귀 호출
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> board(n);             // 퀸 위치 정보를 저장할 보드
    backtracking(board, answer, 0);   // 백트래킹 시행
    
    return answer;
}