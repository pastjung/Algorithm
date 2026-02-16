# import sys
# sys.stdin = open('input.txt')

'''문제 분석
- 문제 설명
- 입력 데이터
    - T : 테스트 케이스
    - N : 지도 한 변의 길이
    - K : 최대 공사 가능 깊이
    - maps : 지도 정보
        - 깊이 : 1 ~ 20
        - 가장 높은 봉우리는 최대 5개
- 핵심 키워드
    - N * N * 4 = 256, 가장 높은 봉우리는 최대 5개 -> 재귀 안 터짐
    - 필요한 경우, 지형을 깎아 높이를 1보다 작게 가능
    - 가장 높은 봉우리들에서 dfs 시작
    - 4방향 확인
        - 그냥 이동 가능하면 이동
        - 불가능하면 K만큼 상/하 확인 + Flag 처리
            - 이때 현재 값 - 1로 재귀
'''

def solve():
    N, K = map(int, input().split())
    maps = [list(map(int, input().split())) for _ in range(N)]

    max_len = 0
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    max_height = max([max(x) for x in maps])
    # max_height = max(map(max, maps))

    def make_load(y, x, visited, flag, depth):
        nonlocal N, K, maps, max_len, max_height, directions

        if depth > max_len:
            max_len = depth
        
        for dy, dx in directions:
            ny = y + dy
            nx = x + dx
            if 0 <= ny < N and 0 <= nx < N and not visited[ny][nx]:
                visited[ny][nx] = True
                
                # 1. 그냥 이동 가능한 경우
                if maps[ny][nx] < maps[y][x]:
                    make_load(ny, nx, visited, flag, depth + 1)

                # 2. 공사를 진행해야 하는 경우(아직 안 깎은 경우)
                elif flag and maps[ny][nx] - K < maps[y][x]:
                    original_height = maps[ny][nx]
                    maps[ny][nx] = maps[y][x] - 1
                    make_load(ny, nx, visited, False, depth + 1)
                    maps[ny][nx] = original_height

                visited[ny][nx] = False

    visited = [[False] * N for _ in range(N)]
    for y in range(N):
        for x in range(N):
            if maps[y][x] == max_height:
                visited[y][x] = True
                make_load(y, x, visited, True, 1)
                visited[y][x] = False

    return max_len
    


T = int(input())
for tc in range(1, T + 1):
    print(f'#{tc} {solve()}')
