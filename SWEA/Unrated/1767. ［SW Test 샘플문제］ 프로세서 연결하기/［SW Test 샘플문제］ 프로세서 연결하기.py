'''문제 분석
- 문제 설명
    - N * N개의 Cell -> board
        - 1개의 cell에는 Core 혹은 전선이 올 수 있음
    - board의 가장 자리에는 전원이 흐름
        - 가장 자리에 위치한 Core는 이미 전원이 연결된 것으로 간주
    - Core와 전원을 연결하는 전선은 직선으로만 설치 가능
    - 전선은 서로 교차 안됨
    - 결론 : 최대한 많은 Core에 전원을 연결하였을 경우, 전선 길의 합이 최소가 되는 경우
        - 전원이 연결되지 않는 Core가 존재할 수 있음
- 입력 데이터
    - T : 테스트 케이스
    - N : board의 크기 (7~12)
    - board : Core의 정보
        - 0 : 빈 Cell
        - 1 : Core
- 핵심 키워드
    - 50개 2초 -> 문제당 0.04초 -> O(400만)
    - 아이디어
        - 각 위치에서 4방향 + 선택X 으로 DFS 탐색
            - 5^N이라서 시간 초과
    - 개선점1
        - 가장자리에 위치한 Core는 제외
        - DFS를 수행할 때, 전선의 길이가 가장 짧은 경우를 먼저 선택
            - 전선이 꼬이는 경우, 다음 길이가 탐색이 되므로, 최초 1회 완성되는 경우가 최단 경로가 됨
        - 즉, DFS + Greedy
    - 개선점2
        - 개선점1은 전선의 길이는 최단 길이가 되지만, 프로세스의 개수가 최대가 되진 않음
        - 완전 탐색(Backtracking)으로 모든 경우 탐색 필요
        - 이때 남은 코어를 다 연결해도 현재까지 찾은 최대 연결 수보다 적은 경우, 가지치기
'''

def solve():
    N = int(input())
    board = [list(map(int, input().split())) for _ in range(N)]

    cores = []
    for y in range(N):
        for x in range(N):
            if board[y][x] == 1:
                # 가장자리 코어 제거
                if 0 < y < N-1 and 0 < x < N-1:
                    cores.append((y, x))

    min_len = N * 12
    max_core = 0
    def cal_min_len(cur_core, cur_len, idx):
        nonlocal min_len, max_core

        # 1. 기저 조건
        if idx == len(cores):
            if cur_core > max_core:
                max_core = cur_core
                min_len = cur_len
            elif cur_core == max_core:
                min_len = min(min_len, cur_len)
            return

        # 2. 가지치기
        if cur_core + (len(cores) - idx) < max_core:
            return

        # 3. 다음 조건 확인 : 4방향 확인
        y, x = cores[idx]
        for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            count = 0
            can_go = False
            ny, nx = y + dy, x + dx
            
            # 1. 해당 방향으로 끝까지 갈 수 있는지 확인
            while 0 <= ny < N and 0 <= nx < N:
                # 코어나 전선이 있으면 실패
                if board[ny][nx] != 0:
                    break
                ny += dy
                nx += dx
             # break 없이 끝까지 도달했다면 (전원 연결 가능)
            else:
                can_go = True
            
            # 2. 갈 수 있다면 전선 표시하고 다음 코어로
            if can_go:
                # 전선 채우기
                sy, sx = y + dy, x + dx
                while 0 <= sy < N and 0 <= sx < N:
                    board[sy][sx] = 2
                    count += 1
                    sy += dy
                    sx += dx
                
                cal_min_len(cur_core + 1, cur_len + count, idx + 1)
                
                # 백트래킹: 전선 다시 지우기
                sy, sx = y + dy, x + dx
                while 0 <= sy < N and 0 <= sx < N:
                    board[sy][sx] = 0
                    sy += dy
                    sx += dx
        
        # 4. 다음 조건 확인 : 선택하지 않는 경우
        cal_min_len(cur_core, cur_len, idx + 1)

    cal_min_len(0, 0, 0)
    return min_len

T = int(input())
for tc in range(1, T + 1):
    print(f'#{tc} {solve()}')