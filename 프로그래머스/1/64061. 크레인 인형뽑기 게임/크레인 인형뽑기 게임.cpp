#include <stack>
#include <vector>
using namespace std;

// 배열의 맨 위을 반환하는 함수
int findTop(vector<vector<int>>& board, int idx){
    int top = 0;
    for(int i = 0; i < board.size(); ++i){
        if(board[i][idx - 1] != 0){
            top = board[i][idx - 1];
            board[i][idx - 1] = 0;
            break;
        }
    }
    return top;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    // 뽑은 순서를 저장한 stack 선언
    stack<int> dolls;
    
    // moves 순서대로 board에서 인형 뽑기
    for(int idx : moves){
	    // 배열의 맨 위 확인
        int doll = findTop(board, idx);
		// 맨 위가 0인 경우 ( 비어있을 경우 ) -> continue;
        if(doll == 0){
            continue;
        }
		// stack이 비어있을 경우 || stack의 top과 배열의 back을 비교 -> 다를 경우 
        if(dolls.empty() || doll != dolls.top()){
		    // 배열의 back을 stack에 push
            dolls.push(doll);
        } else{
            dolls.pop();    // stack의 top을 pop
            answer += 2;    // answer에 2추가
        }      
    }
    
    return answer;
}