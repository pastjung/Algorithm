'''
- 고정된 값
    - x, y의 값
    - N의 값
- a + b = N
- 이전 전개 항에서 (x+y)를 추가로 곱함
    - (x + y)^3 = (x+y)^2 * (x+y) = (x^2 + 2xy + y^2) * (x+y)
    - 즉, 이전 전개 항에서 dp[a][b] = dp[a-1][b] + dp[a][b - 1]
'''

def solve():
    n, a, b = map(int, input().split())
    dp = [([0] * (n+1)) for _ in range(n+1)]

    # 초기 세팅
    dp[0][0] = 1
    dp[0][1] = 1
    dp[1][0] = 1

    for degree in range(2, n + 1):
        for A in range(degree + 1):
            B = degree - A
            dp[A][B] = dp[A - 1][B] + dp[A][B - 1]

    return dp[a][b]

T = int(input())
for tc in range(1, T+1):
    print(f'#{tc} {solve()}')