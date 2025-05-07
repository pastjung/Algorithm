#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// N을 count번 붙인 수 생성
int make_repeated_number(int N, int count) {
    string s = "";
    for (int i = 0; i < count; ++i) {
        s += to_string(N);
    }
    return stoi(s);
}

/*
풀이 방법 ( i+1개의 N을 사용한 집합 )
1. N을 i+1번 붙인 수
2. i개의 N을 사용한 집합 + N의 사칙연산
3. j개의 N을 사용한 집합 + i-j개의 N을 사용한 집합의 사칙연산
*/
int solution(int N, int number) {
    if(N == number) return 1;
    
    vector<unordered_set<int>> dp(9);   // dp[1] ~ dp[8] 사용

    for (int i = 1; i <= 8; ++i) {
        dp[i].insert(make_repeated_number(N, i));  // 1번 과정

        // 2, 3번 과정 : dp[i] = 모든 j (1 ~ i-1)에 대해 dp[j]와 dp[i-j] 조합  // dp[1] = {N}
        for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }

        // 목표 숫자 찾으면 종료
        if (dp[i].count(number)) return i;
    }

    return -1;
}