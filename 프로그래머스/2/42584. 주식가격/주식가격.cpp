#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    // answer 사이즈 설정
    answer.assign(prices.size(), 0);
    
    // 가격이 유지되는지 확인하기 위한 stack 선언 -> {시작 시간, 가격}
    stack<pair<int, int>> s;
    
    // 현재 가격보다 낮은 값이 있는지 stack에서 확인
    for(int i = 0; i < prices.size(); ++i){
        // stack의 top()이 현재 값보다 작을경우 반복
        while(!s.empty() && s.top().second > prices[i]){
            // stack의 top() 추출
            auto pair = s.top();
            s.pop();

            // 떨어지지 않은 시간 계산
            int time = i - pair.first;

            // 계산된 시간 입력
            answer[pair.first] = time;
        }
        // 현재 값 스택에 삽입
        s.push({i, prices[i]});
    }

    // stack에 남아있는 값 모두 계산
    while(!s.empty()){
        // stack의 top() 추출
        auto pair = s.top();
        s.pop();

        // 떨어지지 않은 시간 계산
        int time = prices.size() - 1 - pair.first;

        // 계산된 시간 입력
        answer[pair.first] = time;
    }
    
    return answer;
}