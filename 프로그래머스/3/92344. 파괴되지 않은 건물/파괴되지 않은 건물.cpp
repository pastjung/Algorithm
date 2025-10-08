#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int n = board.size(), m = board[0].size();
    vector<vector<int>> diff(n + 1, vector<int> (m + 1, 0));
    
    // skill 적용
    for(vector<int> s : skill){
        int degree = s[0] == 1 ? -s[5] : s[5];
        diff[s[1]][s[2]] += degree;
        diff[s[3] + 1][s[2]] += -degree;
        diff[s[1]][s[4] + 1] += -degree;
        diff[s[3] + 1][s[4] + 1] += degree;
    }
    
    // 각 행의 누적합 계산
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            diff[i][j] += diff[i][j - 1];
        }
    }
    
    // 각 열의 누적합 계산
    for(int j = 0; j < m; j++){
        for(int i = 1; i < n; i++){
            diff[i][j] += diff[i - 1][j];
        }
    }
    
    // 부서지지 않은 건물의 수 계산
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] + diff[i][j] > 0){
                answer++;
            }
        }
    }
    
    return answer;
}