#include<string>
#include<vector>
using namespace std;

// 4방향 방향 벡터
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

// 적정 위치인지 판단하는 함수
bool isValid(const vector<int>& board, int x, int y){
    int n = board[0] / 2;
    int m = board[1] / 2;
    if(-n <= x && x <= n && -m <= y && y <= m) return true;
    return false;
}

vector<int> solution(vector<string> keyinput, vector<int> board){
    vector<int> answer;
    
    int x = 0, y = 0;  // 현재 위치

    // keyinput에 따라 이동
    for(string str : keyinput){
        if(str == "left" && isValid(board, x - 1, y)){
            x--;
        } else if(str == "right" && isValid(board, x + 1, y)){
            x++;
        } else if(str == "up" && isValid(board, x, y + 1)){
            y++;
        } else if(str == "down" && isValid(board, x, y - 1)){
            y--;
        }
    }
    
    answer = {x, y};    
    return answer;
}