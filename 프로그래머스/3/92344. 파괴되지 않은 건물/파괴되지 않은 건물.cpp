#include <string>
#include <vector>
using namespace std;

/* 문제 분석
- 문제 설명
    - N * M 크기의 행렬 모양의 게임 맵 : board
    - 각 칸에는 내구도를 가진 건물이 존재
    - 적은 건물들을 공격하여 파괴하려 함
    - 공격을 받으면 내구도가 감소하고, 내구도가 0이 되면 파괴
    - 아군은 회복 스킬을 사용하여 건물들의 내구도를 높이려고 함
    - 공격과, 회복은 항상 직사각형 모양으로 시전
    - 회복으로 파괴된 건물이 복구되기도 함
    - 파괴된 건물도 공격 받으면 계속해서 내구도가 하락
    - 모든 동작이 끝난 뒤 파괴되지 않은 건물의 개수 반환
- 입력 데이터
    - 건물의 내구도 board : 1000 * 1000 -> 100만 -> O(NlogN) 알고리즘 사용 가능
    - 공격 혹은 아군 회복 skill : type(1: 공격, 2: 회복), r1, c1, r2, c2, degree -> 최대 25만개
    -> 100만 * 25만 = 250,000,000,000 = 2억 5천 -> 시간 초과
- 핵심 키워드
    - skill을 board에 그냥 적용하면 시간 초과 -> skill을 공격과 회복으로 분리해서 추가적인 처리가 필요
*/

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size(), m = board[0].size();
    
    // (N+1) * (M+1) 사이즈 배열 보드 생성
    vector<vector<int>> diff(n + 1, vector<int>(m + 1, 0));
    
    // sill의 각 모서리 마킹
    for(vector<int> s : skill){
        int degree = s[0] == 1 ? -s[5] : s[5];
        diff[s[1]][s[2]] += degree;
        diff[s[1]][s[4] + 1] += -degree;
        diff[s[3] + 1][s[2]] += -degree;
        diff[s[3] + 1][s[4] + 1] += degree;
    }
    
    // 각 행의 누적합 계산
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            diff[i][j] += diff[i][j - 1];
        }
    }
    
    // 각 열의 누적합 계산
    for(int j = 0; j < m; j++){
        for(int i = 1; i < n; i++){
            diff[i][j] += diff[i-1][j];
        }
    }
    
    // 부서진 건물의 개수 계산
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] + diff[i][j] > 0){
                answer++;
            }
        }
    }
    
    return answer;
}