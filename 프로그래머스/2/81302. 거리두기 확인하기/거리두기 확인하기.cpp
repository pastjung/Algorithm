#include <string>
#include <vector>
using namespace std;

const int SIZE = 5; // 대기실 사이즈

// 방향 벡터 (상하좌우, 대각선)
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {1, -1, 0, 0};
vector<int> dx2 = {1, 1, -1, -1};
vector<int> dy2 = {1, -1, -1, 1};

// 정상 범위 확인 함수
bool check(const vector<string>& place, int x, int y){
    if(0 <= x && x < SIZE && 0 <= y && y < SIZE && place[y][x] == 'P'){
        return true;
    }
    return false;
}

// 대기실이 거리두기를 잘 지키고 있는지 확인하는 함수
int check_Candidate_Distance(vector<string> place){
    // 각 응사자의 위치에서 3가지 경우 확인
    for(int y = 0; y < SIZE; y++){
        for(int x = 0; x < SIZE; x++){
            if(place[y][x] != 'P') continue;
            
            // 상하좌우로 1칸에 응시자가 앉은 경우
            for(int dir = 0; dir < 4; dir++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                
                if(check(place, nx, ny)){
                    return 0;
                }
            }
            
            // 상하좌우로 2칸에 응시자가 앉은 경우
            for(int dir = 0; dir < 4; dir++){
                int ny = y + 2 * dy[dir];
                int nx = x + 2 * dx[dir];
                
                // 두 칸 사이에 파티션이 존재하는 경우 -> 허용
                if(check(place, nx, ny) && place[ny - dy[dir]][nx- dx[dir]] != 'X'){
                    return 0;
                }
            }
                
            // 대각선으로 1칸에 응시자가 앉은 경우
            for(int dir = 0; dir < 4; dir++){
                int ny = y + dy2[dir];
                int nx = x + dx2[dir];
                
                // 두 칸 사이의 양 옆에 파티션이 존재하는 경우 -> 허용
                if(check(place, nx, ny) && (place[y + dy2[dir]][x] != 'X' || place[y][x + dx2[dir]] != 'X')){
                    return 0;
                }
            }
        }
    }
    
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    // 각 대기실이 거리두기를 잘 지키고 있는지 확인
    for(vector<string> place : places){
        answer.push_back(check_Candidate_Distance(place));
    }
    
    return answer;
}