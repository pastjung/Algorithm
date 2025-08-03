#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 유망 함수
bool isPromising(vector<int>& board, int row, int col){
    for (int i = 0; i < row; i++) {
        // 같은 열에 퀸이 있거나, 대각선에 있는 경우
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// 백트래킹
void backtracking(vector<int>& board, int& answer, int row){
    int n = board.size();
    
    // 기저 조건 : 퀸의 개수가 n개인 경우
    if(row == n){
        answer++;
        return;
    }

    // 다음 선택지 탐색 : 가로 내 퀸은 하나만 존재 가능
    for(int col = 0; col < n; col++){
        // 유망성 검사 : 세로 내 퀸 존재 X && 대각선 내 퀸 존재 X
        if(isPromising(board, row, col)){
            board[row] = col;
            backtracking(board, answer, row + 1);     // 재귀 호출
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> board(n);             // 퀸 위치 정보를 저장할 보드
    backtracking(board, answer, 0);   // 백트래킹 시행
    
    return answer;
}