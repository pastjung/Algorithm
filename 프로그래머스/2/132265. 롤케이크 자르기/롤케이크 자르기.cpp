#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> left;   // 왼쪽 토핑 정보
    unordered_map<int, int> right;  // 남아있는 토핑 정보
    
    // 모든 토핑의 수 계산
    for(int t : topping){
        right[t]++;
    }
    
    // 왼쪽에서부터 오른쪽으로 이동하면서 공정한지 확인
    for(int t : topping){
        left[t]++;
        right[t]--;
        
        if(right[t] == 0){
            right.erase(t);
        }
        
        if(left.size() == right.size()){
            answer++;
        }
    }
    
    return answer;
}