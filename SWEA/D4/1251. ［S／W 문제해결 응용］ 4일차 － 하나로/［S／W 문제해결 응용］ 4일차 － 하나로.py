# 최소신장트리(MST, Union&Find): 가중치의 합이 최소가 되는 경우
def mst():
    V = int(input())
    X = list(map(int, input().split()))
    Y = list(map(int, input().split()))
    E = float(input())
    edges = []
    for n1 in range(V):
        for n2 in range(n1, V):
            L = E * ((X[n1] - X[n2])**2 + (Y[n1] - Y[n2])**2)
            edges.append((n1, n2, L))

    def kruskal(V, edges):
        parents = list(range(V + 1))
        ranks = [0] * (V + 1)
        
        def find(x):
            if parents[x] == x:
                return x
            else:
                parents[x] = find(parents[x])
                return parents[x]
    
        def unionSet(u, v):
            rootU = find(u)
            rootV = find(v)

            if rootU != rootV:
                if ranks[rootU] < ranks[rootV]:
                    parents[rootU] = rootV
                elif ranks[rootU] > ranks[rootV]:
                    parents[rootV] = rootU
                else:
                    parents[rootV] = rootU
                    ranks[rootU] += 1
                return True
            return False

        sorted_edges = sorted(edges, key=lambda edge: edge[2])
        total_weights = 0
        for u, v, w in sorted_edges:
            if unionSet(u, v):
                total_weights += w

        return total_weights

    def prim(start, V, edges):
        import heapq

        # 2차원 양방향 인접 리스트 생성: arr[u] = (비용, v)
        adl = [[] for _ in range(V + 1)]
        for u, v, w in edges:
            adl[u].append((w, v))
            adl[v].append((w, u))

        visited = [False] * (V + 1)
        min_heap = [(0, start)] # (비용, 도착점)

        # 초기 세팅
        total_weights = 0
        visited_count = 0

        while min_heap:
            # 1. 최소 가중치 선택
            weight, end = heapq.heappop(min_heap)

            # 2. 이미 방문한 정점인 경우 -> 무시
            if visited[end]:
                continue

            # 3. 방문 처리
            visited[end] = True
            visited_count += 1
            total_weights += weight

            # 4. 모든 정점을 다 찾은 경우 -> 조기 종료
            if visited_count == V + 1:
                break

            # 5. 연결된 간선 탐색
            for next_weight, next_node in adl[end]:
                if not visited[next_node]:
                    heapq.heappush(min_heap, (next_weight, next_node))
                
        return total_weights

    # return int(kruskal(V, edges) + 0.5)
    return int(prim(1, V, edges) + 0.5)

T = int(input())
for tc in range(1, T+1):
    print(f'#{tc} {mst()}')