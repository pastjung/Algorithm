#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> priceStack;
    int N = prices.size();
    
    for(int idx = 0; idx < N; idx++){
        // 가격이 큰 순서로 스택에 삽입 -> top보다 작은 값을 만날 경우 pop()
        while(!priceStack.empty() && prices[priceStack.top()] > prices[idx]){
            answer[priceStack.top()] = idx - priceStack.top();
            priceStack.pop();
        }
        
        // 현재 값 삽입
        priceStack.push(idx);
    }
    
    // 모든 값 비교 후 남은 값들 시간 계산
    while(!priceStack.empty()){
        answer[priceStack.top()] = N - priceStack.top() - 1;
        priceStack.pop();
    }
    
    return answer;
}