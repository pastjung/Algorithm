#include <string>
#include <vector>
using namespace std;

/* 문제 분석
- 문제 설명
    - 배달할 물건은 모두 크기가 동일한 상자에 담아서 배달
    - 배달을 다니면서 빈 재활용 택배 상자 수거
    - 배달할 집은 일렬로 배치 -> i번째 집은 i만큼 떨어져 있음
    - 트럭 하나로 모든 배달과 수거를 마치고 물류창고까지 돌아올 수 있는 최소 이동 거리 계산
- 입력 데이터
    - 트럭에 실을 수 있는 상자 수 cap : 최대 50
    - 집 n : 최대 10만 -> O(NlogN) 알고리즘 사용 가능
    - 각 집에 배달할 물품 수 deliveries : 최대 n개
    - 각 집에서 수거할 택배 상자 수 pickups : 최대 n개
- 핵심 키워드(알고리즘 및 시간 복잡도)
    - 멀리 있는 곳 먼저 이동 & 반복 -> reverse해서 계산하면 될듯?
        - 배달 가면서, 오면서 각각 거리 추가 필요
    - 배달은 가면서, 수거는 돌아오면서
*/

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    // 가장 멀리 있는 값
    int d = n - 1;      // 배달해야 하는 거리 중 최대 거리
    int p = n - 1;      // 수거해야 하는 거리 중 최대 거리
    int dist = n - 1;   // 가장 멀리 이동하는 거리
    
    // 모든 배달 및 수거가 끝날 때 까지 반복
    while(d >= 0 || p >= 0){
        // 배달, 수거 각각 남아 있는 가장 먼 거리 계산
        while(d >= 0 && deliveries[d] == 0) d--;
        while(p >= 0 && pickups[p] == 0)    p--;
        
        // 더 이상 배달/수거할 것이 없으면 종료
        if (d < 0 && p < 0) break;
        
        dist = max(d, p);           // 가장 멀리 이동하는 거리 계산
        answer += (dist + 1) * 2;   // 가장 멀리 있는 값 * 2만큼 이동 거리 추가
        
        // 가장 멀리 있는 값부터 cap까지 최대한 채우고, 남은 배달 차감
        int delivery_cap = cap;
        while(d >= 0 && delivery_cap > 0){
            int deliver = min(deliveries[d], delivery_cap);
            deliveries[d] -= deliver;
            delivery_cap -= deliver;
            if(delivery_cap > 0){
                d--;
            }
        }
        
        // 배달을 마치고 돌아가는 길에 최대한 멀고, 가득 수거
        int prickup_cap = cap;
        while(p >= 0 && prickup_cap > 0){
            int deliver = min(pickups[p], prickup_cap);
            pickups[p] -= deliver;
            prickup_cap -= deliver;
            if(prickup_cap > 0){
                p--;
            }
        }
    }
    
    return answer;
}