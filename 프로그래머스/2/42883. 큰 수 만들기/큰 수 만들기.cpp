#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = number;
    
    // 매 순간 가장 큰 수가 되는 값 찾기
    for(int K = 1; K <= k; K++) {
        int idx = answer.size() - 1;
        for(int i = 0; i < answer.size() - 1; i++){
            if(answer[i] < answer[i + 1]){
                idx = i;
                break;
            }
        }
        
        // 숫자가 내림차순인 경우
        answer.erase(idx, 1);
    }
    
    return answer;
}