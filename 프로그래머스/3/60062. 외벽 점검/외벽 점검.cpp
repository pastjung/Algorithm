#include <string>
#include <vector>
#include <stack>
using namespace std;

/* 문제 분석
- 문제 설명
    - 구조: 동그란 모양
    - 외벽의 총 둘레 : n미터
    - 취약 지점 존재
    - 내부 공사 도중 외벽의 취약 지점들이 손상되지 않았는지, 주기적으로 점검 필요
    - 점검 시간은 1시간으로 제한
    - 친구들이 1시간 동안 이동할 수 있는 거리는 제각각
    - 최소한의 친구들을 투입해 취약 지점 점검
    - 편의상 레스토랑 정북 방향 지점을 0으로 설정, 정북 방향 지점부터 시계방향으로 떨어진 거리로 나타냄
    - 친구는 시계 or 반시계 방향으로 외벽을 따라서 이동 가능
    - 결론: 취약 지점을 점검하기 위해 보내야 하는 친구 수의 최소값
- 입력 데이터
    - 외벽의 길이 n
    - 취약 지점의 위치가 담긴 배열 weak
    - 각 친구가 1시간 동안 이동할 수 있는 거리가 담긴 배열 dist
- 핵심 키워드
    - 친구 수의 최소값 -> 거리를 최대한 딱 맞게 설정해야 함 -> backtracking
    - 시계 방향으로만 설정해도 반시계 방향으로 이동하는 것과 동일하므로 시계방향만 고려
    - 시작 위치는 상관 없음 -> 0번 부터 시작해서 기존에 배치된 친구가 없을 경우 각 시작 지점에 친구 배치 시작
        - stack에 남아있는 취약 지점 저장
            - 다음 backtracking 전 stack에서 pop
            - backtracking 수행 후 stack에 push
        - stack이 비어 있을 경우 -> backtracking 종료 -> 친구 수 갱신
*/

int answer = -1;

void backtracking(int n, const vector<int>& weak, const vector<int>& dist, vector<bool>& worked, int w, int d){
    // 가지치기: 이미 사용한 친구 수(d)가 현재 최적값 이상이면 더 이상 진행할 필요 없음
    if (answer != -1 && d >= answer){
        return;  
    } 
    
    // 모든 취약점을 커버한 경우
    if(w >= weak.size()){
        answer = (answer == -1) ? d : min(answer, d);
        return;
    }
    
    // 기저조건: 더 사용할 친구가 없으면 실패(더 이상 재귀 X)
    if(d == dist.size()){
        return;
    }
    
    // 현재 위치에 친구 배치 -> 현재 친구가 커버 가능한 지점까지 전부 커버
    for(int i = 0; i < worked.size(); i++){
        if(worked[i]) {
            continue;
        }
        
        worked[i] = true;
        
        int end = weak[w] + dist[i];
        int nextW = w;
        while(nextW < (int)weak.size() && weak[nextW] <= end){
            nextW++;
        }
        
        backtracking(n, weak, dist, worked, nextW, d + 1);
        worked[i] = false;
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int m = weak.size();
    // 원형을 선형으로 확장
    vector<int> linear;
    linear.reserve(2 * m);
    for (int i = 0; i < m; ++i) linear.push_back(weak[i]);
    for (int i = 0; i < m; ++i) linear.push_back(weak[i] + n);

    // 각 시작점마다 회전된 weak(길이 m)를 만들어서 backtracking에 넘김
    for (int start = 0; start < m; ++start) {
        vector<int> rotated;
        rotated.reserve(m);
        for (int k = 0; k < m; ++k) rotated.push_back(linear[start + k]);

        // worked는 각 시작점마다 초기화해야 함
        vector<bool> worked(dist.size(), false);

        // backtracking은 w=0, d=0으로 시작
        backtracking(n, rotated, dist, worked, 0, 0);

        if (answer == 1) break; // 더 작아질 수 없으므로 빠른 종료
    }

    return answer;
}