#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// 우선순위 : 소요시간 > 요청 시각 > 번호
struct CustomCompare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1]) return a[1] > b[1];
        if (a[0] != b[0]) return a[0] > b[0];
        return a[2] > b[2];
    }
};

// jobs : 작업이 요청되는 시점, 작업의 소요시간 -> jobs가 작업이 요청되는 시점이 정렬되어 있다고 가정(?)
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<vector<int>> hardDisk;
    priority_queue<vector<int>, vector<vector<int>>, CustomCompare> waitingQueue;   // 대기 큐
    multimap<int, int> jobsMap; // 작업 요청 시간 순으로 정렬된 작업
    
    for(int i = 0; i < jobs.size(); i++){
        jobs[i].push_back(i);
        jobsMap.insert({jobs[i][0], i});
        answer -= jobs[i][0];
    }
    
    int time = -1;      // 모든 작업을 처리하는데 걸린 시간
    int startTime = 0;  // 작업을 시작한 시간
    do {           
        // 모든 작업이 완료되었는지 확인
        if(hardDisk.empty() && waitingQueue.empty() && jobsMap.empty()){
            break;
        } else {
            time++;
        }
        
        // 새로운 작업 요청이 있는지 확인 -> 대기 큐에 저장
        auto it = jobsMap.find(time);
        while(it != jobsMap.end() && it->first == time){
            int idx = it->second;
            waitingQueue.push(jobs[idx]);
            it = jobsMap.erase(it);
        }       
        
        // 작업중인 작업이 마무리 되었는지 확인
        if(!hardDisk.empty() && time - startTime == hardDisk[0][1]){
            answer += time;
            hardDisk.pop_back();
        }
        
        // 작업이 마무리 되었다면 새로운 작업 시작
        if(hardDisk.empty() && !waitingQueue.empty()){
            startTime = time;
            hardDisk.push_back(waitingQueue.top());
            waitingQueue.pop();
        }
        
    } while(true);
    
    return answer / jobs.size();
}