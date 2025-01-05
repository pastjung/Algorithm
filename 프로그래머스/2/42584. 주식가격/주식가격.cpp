#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    for(int i = 0; i < prices.size() - 1; i++){
        answer[i]++;
        for(int j = i + 1; j < prices.size() - 1; j++){
            if(prices[i] <= prices[j]){
                answer[i]++;
            } else {
                break;
            }
        }
    }
    
    return answer;
}