#include <string>
#include <vector>
using namespace std;

/* 문제 분석
- 문제 설명 ( 미로 탈출 )
    - 출발/도착 위치 격자 포함 같은 격자 중첩 방문 가능
    - 탈출 경로를 문자열로 나타냈을 때, 사전순 가장 빠른 경로
        - 이동 경로 : 왼쪽(l), 오른쪽(r), 위(u), 아래(d) -> ex) "lul"
    - 주어진 조건대로 탈출 불가능할 경우 "impossible" 반환
- 입력 데이터
    - 격자 미로 (n * m) : 최대 50
    - 출발 위치 S(x, y) : 최대 50
    - 도착 위치 E(r, c)
    - 최대 이동 거리 k 
    => n*m = 50*50 = 2500 -> O(N^2) 알고리즘 사용 가능
- 핵심 키워드(알고리즘 및 시간 복잡도)
    - 탈출 경로 탐색 : DFS(백트래킹) or BFS
    - 사전 순 빠른 경로 : d -> l -> r -> u 순서로 이동 => 백트래킹 탐색
    - 네 방향 이동 : 방향 벡터 사용
*/

// 방향 벡터
vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, -1, 1, 0};
vector<char> direction = {'d', 'l', 'r', 'u'};

// DFS
bool DFS(int n, int m, int x, int y, int r, int c, int k, string& answer, string path){
    // 기저 조건
    if(k == 0){
        if(x == r && y == c){
            answer = path;
            return true;
        }
        return false;
    }
    
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(1 <= nx && nx <= n && 1 <= ny && ny <= m){
            // 가지치기
            int dist = abs(nx - r) + abs(ny - c);
            if(dist > k - 1) continue;
            if((k - 1 - dist) % 2 != 0) continue;
            
            // 인접 위치 이동
            if(DFS(n, m, nx, ny, r, c, k - 1, answer, path + direction[dir])) return true;
        }
    }
    return false;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "impossible";
    DFS(n, m, x, y, r, c, k, answer, "");
    return answer;
}