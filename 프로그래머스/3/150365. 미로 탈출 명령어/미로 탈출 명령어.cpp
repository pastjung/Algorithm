#include <string>
#include <vector>
#include <cmath>
using namespace std;

/* 문제 분석
- 문제 설명
    - n*m 격자 미로
    - (x, y)에서 출발
    - (r, c)로 도착
    - 격자 밖으로 나갈 수 없음
    - (x, y) -> (r, c) 이동 거리가 총 k여야 함
    - 동일한 격자를 두 번 이상 방문해도 됨
    - 미로를 탈출할 수 없는 경우 impossible 반환
    - 결론: 미로에서 탈출한 경로를 문자열로 나타냈을 때, 문자열이 사전 순으로 가장 빠른 경로로 탈출
- 입력 데이터
    - n*m 격자 크기
        - 세로의 길이 : n
        - 가로의 길이 : m
    - 출발 위치 x, y
    - 도착 위치 r, c
    - 이동 횟수 k
- 핵심 키워드
    - 두 번 이상 방문 가능 -> 매 순간 4방향 모두 확인
    - 문자열이 사전 순으로 가장 빠른 경로 -> 즉, d, l, r, u 순서로 탐색
    - k번 이동 -> 즉, 각 위치에서 |r - x| + |c - y| <= k 를 만족해야 함
    - 결론: 백트래킹
*/

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, -1, 1, 0};
const char direction[4] = {'d', 'l', 'r', 'u'};

// 유망 함수 -> 보드에서 넘어가는지 확인
bool promising(int n, int m, int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

// 백트래킹(보드, 현재 위치, 도착 위치, 남은 이동 횟수)
void backtracking(int n, int m, int x, int y, int r, int c, int k, string& answer, string path){
    // 가지치기: 현재 위치가 |r - x| + |c - y| > k인 경우 -> 종료
    int dist = abs(r - x) + abs(c - y);
    if(dist > k || (k - dist) % 2 != 0){
        return;
    }
    
    // 기저 조건: 이동 가능 횟수가 없는 경우 -> 종료
    if(k == 0){
        if(x == r && y == c){
            answer = path;
        }
        return;
    }

    // 인접 4방향 확인
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(!promising(n, m, nx, ny)){
            continue;
        }
        
        backtracking(n, m, nx, ny, r, c, k - 1, answer, path + direction[dir]);
        if (answer != "impossible"){
            return;
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "impossible";
    backtracking(n, m, x - 1, y - 1, r - 1, c - 1, k, answer, "");
    return answer;
}