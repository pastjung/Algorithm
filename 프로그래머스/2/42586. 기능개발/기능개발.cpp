#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    // 작업을 관리할 큐 선언
    queue<pair<int, int>> q;
    
    // 큐에 현재 진행 상황 progresses 입력
    for(int i = 0; i < progresses.size(); i++){
        q.push({progresses[i], speeds[i]});
    }
    
    // 큐가 비워질 때 까지 반복
    while(!q.empty()){
        // 오늘 배포한 작업의 수 정의
        int task = 0;
        
	    // 첫번째 작업이 배포 가능할 경우 -> 연속된 완료된 작업 모두 같이 배포
        while(!q.empty() && q.front().first >= 100){
            task++;
            q.pop();
        }
	    // 배포한 작업 수 answer에 push
        if(task != 0){
            answer.push_back(task);
        }
        
        // 큐가 비어있을 경우 종료
        if(q.empty()){
            break;
        }
	    
	    // 나머지 작업은 작업 진행도에 speeds를 더한 값을 다시 큐에 push 후 pop
        for(int i = 0; i < q.size(); i++){
            q.push({q.front().first + q.front().second, q.front().second});
            q.pop();
        }
    }
    
    return answer;
}