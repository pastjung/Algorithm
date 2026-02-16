# import sys
# sys.stdin = open('input.txt')

'''문제 분석
- 문제 설명
    - N명의 학생의 키 비교
    - N명의 키는 모두 다름
    - 일부 데이터만 존재 -> 일부 학생은 가장 작은 학생부터 몇 번째인지 알 수 있음
        - a번 학생의 키가 b번 학생보다 작다면, a -> b
    - 결론: 자신의 키가 몇 번째인지 알 수 있는 학생들이 몇 명인지 계산
- 입력 데이터
    - T : 테스트 케이스
    - N : 학생들의 수
    - M : 두 학생의 키를 비교한 횟수
    - compares : 두 학생의 키 비교
        - a b : a -> b (a < b)
- 핵심 키워드
    - 아이디어
        - 나보다 키가 큰 사람 + 작은 사람 = 전체 인원 - 1
'''

def solve():
    N = int(input())
    M = int(input())

    taller = [[] for _ in range(N + 1)]  # 본인보다 큰 학생 저장
    smaller = [[] for _ in range(N + 1)] # 본인보다 작은 학생 저장

    for _ in range(M):
        a, b = map(int, input().split())
        taller[a].append(b)
        smaller[b].append(a)

    def cal_student(start_student, adj):
        stack = [start_student]
        visited = [False] * (N + 1)

        # 초기 세팅
        visited[start_student] = True
        count = 0

        # 연결된 정보 확인
        while stack:
            cur_student = stack.pop()
            for next_student in adj[cur_student]:
                if not visited[next_student]:
                    visited[next_student] = True
                    count += 1
                    stack.append(next_student)
        
        return count

    result = 0
    for student in range(1, N + 1):
        if cal_student(student, taller) + cal_student(student, smaller) == N - 1:
            result += 1

    return result
    

T = int(input())
for tc in range(1, T + 1):
    print(f'#{tc} {solve()}')
