#include<vector>
#include<algorithm>
using namespace std;

int bottom_up(vector<vector<int>> board){
    int ROW = board.size(), COL = board[0].size();
    
    for(int i = 1; i < ROW; i++){
        for(int j = 1; j < COL; j++){
            if(board[i][j] == 0) continue;
            board[i][j] = min({board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]}) + 1;
        }
    }
    
    int maxLen = 0;
    for(const auto& row : board){
        maxLen = max(maxLen, *max_element(row.begin(), row.end()));
    }    
    return maxLen;
}

int solution(vector<vector<int>> board){
    int len = bottom_up(board);
    return len * len;
}