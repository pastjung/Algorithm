def solve():
    N = int(input())
    M = int(input())

    taller = [[] for _ in range(N + 1)]
    smaller = [[] for _ in range(N + 1)]

    # 자신보다 큰 사람/작은 사람 정보를 저장
    for _ in range(M):
        a, b = map(int, input().split())
        taller[a].append(b)
        smaller[b].append(a)

    # 자신보다 큰 사람/작은 사람을 계산하는 함수
    def cal_student(start, adj):
        for next in adj[start]:
            if not visited[next]:
                visited[next] = 1
                cal_student(next, adj)

    # 자신보다 큰 사람 + 작은 사람 + 본인 = N
    result = 0
    for student in range(1, N + 1):
        visited = [0] * (N + 1)

        # 초기화
        visited[student] = 1
        
        cal_student(student, taller)
        cal_student(student, smaller)
        
        if sum(visited) == N:
            result += 1

    return result

T = int(input())
for tc in range(1, T+1):
    print(f'#{tc} {solve()}')