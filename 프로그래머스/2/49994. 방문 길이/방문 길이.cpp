#include <string>
#include <vector>
using namespace std;

// 4방향 방향 벡터 선언
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

// 특정 좌표에서 특정 방향으로 이동한 적이 있는지 확인하는 3차원 배열 선언
bool visited[11][11][4];

// 방향 계산 함수
int nextDir(char d){
    if(d == 'U'){
        return 0;
    } else if(d == 'R'){
        return 1;
    } else if(d == 'D'){
        return 2;
    } else {
        return 3;
    }
}

// 좌표 검증 함수
bool isValid(int x, int y){
    if(0 <= x && x <= 10 && 0 <= y && y <= 10){
        return true;
    } else {
        return false;
    }
}

int solution(string dirs) {
    int answer = 0;
    
    // 좌표계 선언
    vector<vector<int>> board(11, vector<int>(11, 1));
    
    // 시작 위치 선언
    int x = 5, y = 5;
    
    // dirs의 방향 확인
    for(char d : dirs){
        // 이동 좌표 계산
        int dir = nextDir(d);
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 다음 위치의 좌표계 범위 확인
        if(!isValid(nx, ny)){
            continue;
        }

        // 중복 확인
        if(!visited[y][x][dir]){
            visited[y][x][dir] = true;
            visited[ny][nx][(dir + 2) % 4] = true;
            answer++;
        }

        // 다음 좌표 설정
        x = nx;
        y = ny;
    }
    
    return answer;
}