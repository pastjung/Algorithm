#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    
    queue<int> bridge;      // 다리를 건너는 트럭 : truck_weights의 index 저장
    int bridge_weight = 0;  // 다리를 건너고 있는 트럭의 총 무게
    int now = 0;
    do {
        answer++;
        // 다리를 지난 트럭이 있는 경우
        if(bridge.size() == bridge_length){
            int idx = bridge.front();
            bridge.pop();
            if(idx != -1){
                bridge_weight -= truck_weights[idx];
            }
        }
        
        // 대기중인 트럭이 있는 경우
        if(now < truck_weights.size()){
            // 다리에 트럭이 더 올라갈 수 있는 경우
            if(bridge.size() < bridge_length && bridge_weight + truck_weights[now] <= weight){
                bridge.push(now);
                bridge_weight += truck_weights[now];
                now++;
            } else {
                bridge.push(-1);
            }
        } else {
            answer += bridge_length - 2;
            break;
        }
        
    } while(!bridge.empty());
    
    return answer;
}