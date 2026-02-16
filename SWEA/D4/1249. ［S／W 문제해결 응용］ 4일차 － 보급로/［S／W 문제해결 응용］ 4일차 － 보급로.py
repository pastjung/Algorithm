# import sys
# sys.stdin = open('input.txt')
import heapq

'''문제 분석
- 문제 설명
    - 결론: 출발지에서 도착지까지 가는 경로 중 복구 시간이 가장 짧은 경로에 대한 총 복구 시간 구하기
    - 상하좌우 방향으로 이동
- 입력 데이터
    - T : 테스트 케이스
    - N : 지도의 크기
    - board : 지도 정보
        - S : 출발지 (0, 0)
        - G : 도착지 (N-1, N-1)
- 핵심 키워드
    - 다익스트라
'''

def solve():
    N = int(input())
    board = [list(map(int, input().strip())) for _ in range(N)]

    directions = [(0, 1), (1, 0), (-1, 0), (0, -1)]

    def dijkstra():
        dist = [[float('inf')] * N for _ in range(N)]
        pq = [(0, (0, 0))]

        # 초기 세팅
        dist[0][0] = 0
        heapq.heapify(pq)

        # 인접 위치 확인
        while pq:
            cost, (y, x) = heapq.heappop(pq)
            
            # 이미 최적화한 경우가 있는 경우
            if cost > dist[y][x]:
                continue

            # 도착점에 도달한 경우
            if y == N - 1 and x == N - 1:
                return cost

            # 다음 방향 탐색
            for dy, dx in directions:
                ny = y + dy
                nx = x + dx
                if 0 <= ny < N and 0 <= nx < N:
                    next_cost = cost + board[ny][nx]

                    # 새로운 비용이 기존 비용보다 작을 때만 갱신
                    if next_cost < dist[ny][nx]:
                        dist[ny][nx] = next_cost
                        heapq.heappush(pq, (next_cost, (ny, nx)))

        return dist[N - 1][N - 1]
    
    return dijkstra()

T = int(input())
for tc in range(1, T + 1):
    print(f'#{tc} {solve()}')