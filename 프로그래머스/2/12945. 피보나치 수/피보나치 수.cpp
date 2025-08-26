#include <vector>
using namespace std;

// bottom-up 방식의 dp 구현
int bottom_up(int n){
    vector<int> dp = {0, 1};
    for(int i = 2; i <= n; i++){
        dp.push_back((dp[i - 1] + dp[i - 2]) % 1234567);
    }
    return dp[n];
}

int solution(int n) {
    return bottom_up(n);
}