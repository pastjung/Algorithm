'''
- 고정된 값
    - 물건의 종류
    - 물건의 크기
    - 박스의 무게
- 변동하는 값 & 구해야 하는 값
    - 가격 합계 -> 최대 값 => dp에 결과 값 저장
- dp[박스의 무게] = 가격의 합

for 물건의 종류(1~M) wm
    for 물건의 무게(1~N, 역순) w
        dp[w] = max(dp[w], dp[w-wm] + value_m)
'''

def solve():
    N, M = map(int, input().split())
    items = [list(map(int, input().split())) for _ in range(M)]
    dp = [0] * (N+1)

    for s, p in items:
        for w in range(N, s - 1, -1):
            dp[w] = max(dp[w], dp[w - s] + p)

    return dp[N]

T = int(input())
for tc in range(1, T+1):
    print(f'#{tc} {solve()}')