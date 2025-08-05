#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    // 예산이 적은 순서로 정렬
    sort(d.begin(), d.end());
    
    // 예산이 적은 순서로 지원
    for(int i : d){
        if(i <= budget){
            answer++;
            budget -= i;
        }
    }
    
    return answer;
}