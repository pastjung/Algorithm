#include <string>
#include <vector>
using namespace std;

/* 문제 분석
- 문제 설명
    - 피로도를 사용해 던점 탐험
    - 최소 필요도와 소모 피로도 존재
        - 최소 피로도 : 던점을 탐험하기 위한 피로도
        - 소모 피로도 : 던전 후 소모되는 피로도
    - 각 던전은 하루에 한 번씩 탐험 가능
    - 결로: 유저가 탐험할 수 있는 최대 던전 수 반환
- 입력 데이터
    - 현재 피로도 k
    - 각 던전별 (최소 필요 피로도, 소모 피로도) dungeons
- 핵심 키워드
    - 하루에 한 번만 탐험 가능 -> 탐험 순서 결정하기 -> 순열 -> 백트래킹
*/

void backtracking(const vector<vector<int>>& dungeons, vector<bool>& visited, int& answer, int k, int visit){
    // 기저 조건: X
    
    // 던전의 최대 방문 수 갱신
    answer = max(answer, visit);
    
    // 다음 던전 탐색
    for(int i = 0; i < dungeons.size(); i++){
        // 유망성 검사: 방문 여부 && 최소 피로도 <= 현재 피로도
        if(!visited[i] && dungeons[i][0] <= k){
            visited[i] = true;  // 방문 처리
            backtracking(dungeons, visited, answer, k - dungeons[i][1], visit + 1);  // 다음 던전 방문
            visited[i] = false; // 선택 취소
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);   // 방문 여부를 저장할 배열
    backtracking(dungeons, visited, answer, k, 0);  // 백트래킹 수행
    return answer;
}