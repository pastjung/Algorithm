def solve():
    N = int(input())
    arr = list(map(int, input().split()))

    def lis(N, arr):
        if N == 0:
            return 0

        # dp[i] : arr[i]를 마지막 원소로 가지는 LIS의 길이
        dp = [1] * N

        for i in range(N):
            for j in range(i):
                if arr[j] < arr[i]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)

    return lis(N, arr)

T = int(input())
for tc in range(1, T+1):
    print(f'#{tc} {solve()}')