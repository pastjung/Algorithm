'''
- 고정된 값: 원소의 합, 원소의 개수
- dp[원소의 종류][원소의 합] = 부분 조합의 수


for 원소의 종류 i
    for 원소의 합(해당 원소~N) : s
        # 포함하지 않는 경우
        dp[i][s] = dp[i - 1][s]
        
        # 포함 시키는 경우
        dp[i][s] = max(dp[i][s], dp[i - 1][s - i] + 1)
        dp[i][s] += dp[i - 1][s - i]

return dp[N][K]
'''

def solve():
    N, K = map(int, input().split())
    dp = [[0] * (K + 1) for _ in range(N + 1)]

    dp[0][0] = 1

    for n in range(1, N + 1):
        for k in range(K + 1):
            # 포함하지 않는 경우
            dp[n][k] = dp[n - 1][k]

            # 포함하는 경우
            if k >= n:
                dp[n][k] += dp[n - 1][k - n] # 경우의 수 누적
                # dp[n][k] = max(dp[n][k], dp[n - 1][k - n] + 1) # 최대 원소의 개수 파악
    return dp[N][K]

T = int(input())
for tc in range(1, T+1):
    print(f'#{tc} {solve()}')