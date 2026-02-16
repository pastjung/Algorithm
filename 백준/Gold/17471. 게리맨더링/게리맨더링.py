from itertools import combinations
from collections import deque

'''문제 분석
- 문제 설명
    - N개의 구역(1~N)
    - 구역을 두 개의 선거구로 나눔
        - 각 구역은 두 선거구 중 하나에 포함
        - 선거구는 구역을 적어도 하나 포함
        - 한 선거구에 포함되어 있는 구역은 모두 연결
    - 결론: 두 선거구에 포함된 인구의 차이를 최소로 하는 최솟값 계산
        - 두 선거구로 나눌 수 없는 경우에는 -1을 출력
- 입력 데이터
    - N : 구역의 개수 (1~10)
    - peoples : 구역의 인구 수
    - edges : 인접한 구역의 정보
- 핵심 키워드
    - 시간 제한 : 0.5초 -> O(5,000만)
    - 모든 인구 수를 미리 저장

    - 방법1) r = 1부터 n // 2까지 nCr을 구하기
        - 해당 조합이 연결 가능한 경우인지 확인 + 인구 수 계산 -> bfs
        - 만약 중간에 기존 최솟값을 넘어갈 경우 조기 종료

    - 방법2) 딕셔너리에 이전 부분 집합에 대해서 인원 수를 기록
        - dfs로 전체 조합에서 1개씩 뺀 경우로 재귀 탐색 -> 리프에서부터 1개씩 추가
        - 이때 이전 연산한 인원 수에서 추가하는 방식으로 구현 (메모이제이션)
'''

N = int(input())
people = [0] + list(map(int, input().split()))
edges = [[]]
for _ in range(N):
    data = list(map(int, input().split()))
    edges.append(data[1:])

MAX_NUM = 100 * N

def solve():
    # 특정 조합이 서로 연결되어 있는지 확인 + 인구 합 반환
    def cal_comb(comb):
        visited = [0] * (N + 1)
        q = deque()

        # 초기 세팅
        visited[comb[0]] = 1
        q.append(comb[0])
        total = people[comb[0]]

        # BFS 탐색
        while q:
            cur = q.popleft()
            for next_node in edges[cur]:
                if next_node in comb and not visited[next_node]:
                    visited[next_node] = 1
                    total += people[next_node]
                    q.append(next_node)


        # 조합의 연결이 불가능한 경우
        if sum(visited) != len(comb):
            return MAX_NUM

        return total
    
    min_diff = MAX_NUM
    for r in range(1, N // 2 + 1):
        for comb in combinations(list(range(1, N + 1)), r):
            n1 = cal_comb(comb)
            n2 = cal_comb(tuple(set(range(1, N + 1)) - set(comb)))
            if n1 != MAX_NUM and n2 != MAX_NUM:
                min_diff = min(min_diff, abs(n1 - n2))
    
    return min_diff if min_diff != MAX_NUM else -1

print(solve())

