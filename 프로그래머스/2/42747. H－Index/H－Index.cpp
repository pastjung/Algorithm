#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<>());  // 내림차순 정렬
    
    for(int i = 0; i < citations.size(); i++){
        if(citations[i] >= i + 1){
            answer = i + 1;
        }
    }
    
    return answer;
}