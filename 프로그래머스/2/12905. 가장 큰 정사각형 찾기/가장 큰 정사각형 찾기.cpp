#include<vector>
#include<algorithm>
using namespace std;

int bottom_up(vector<vector<int>> board){
    int maxLen = 0;
    
    for(int i = 0; i < board.size(); i++){
        maxLen = max(maxLen, board[i][0]);
    }
    for(int i = 0; i < board[0].size(); i++){
        maxLen = max(maxLen, board[0][i]);
    }
    
    for(int i = 1; i < board.size(); i++){
        for(int j = 1; j < board[i].size(); j++){
            if(board[i][j] == 0) continue;
            board[i][j] = min({board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]}) + 1;
            maxLen = max(maxLen, board[i][j]);
        }
    }
    return maxLen;
}

int solution(vector<vector<int>> board){
    int len = bottom_up(board);
    return len * len;
}