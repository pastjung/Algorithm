#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow; // 전체 타일 수
    
    // 세로의 길이가 3 ~ sqrt(전체 타일 수) 구간을 확인
    for(int col = 3; col <= sqrt(total); col++) {
        // 직사각형을 만들 수 없는 경우 : 전체 타일 수 % 세로 길이 != 0
        if(total % col != 0) continue;
           
        // 카펫을 만들 수 없는 경우 : ((가로 - 1) + (세로 - 1)) * 2 != brown
        int row = total / col;
        if(2 * (row + col - 2) != brown) continue;
        
        // 카펫을 만든 경우
        answer = {row, col};
        break;
    }
    
    return answer;
}