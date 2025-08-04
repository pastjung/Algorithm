#include <string>
#include <vector>
using namespace std;

// 백트래킹
void backtracking(vector<vector<int>>& dungeons, vector<bool>& visited, int& answer, int k, int count){
    // 던전의 최대 방문수 갱신
    if(answer < count){
        answer = count;
    }
    
    // 다음 던전 탐색
    for(int i = 0; i < dungeons.size(); i++){
        // 유망성 검사 : 중복 제거 || 최소 필요도 < 현재 필요도
        if(!visited[i] && k >= dungeons[i][0]){
            visited[i] = true;                                                          // 선택 : 해당 던전 탐험
            backtracking(dungeons, visited, answer, k - dungeons[i][1], count + 1);     // 재귀 호출
            visited[i] = false;                                                         // 선택 취소
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);   // 방문 여부를 기록할 배열
    backtracking(dungeons, visited, answer, k, 0);  // 백트래킹 수행
    return answer;
}