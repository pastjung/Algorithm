#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int idx = 0;    // 기능 개선 작업중인 위치
    for(int time = 1; time <= 100; time++){
        if(idx > progresses.size()){
            break;
        }
        
        int count = 0;  // 동일한 배포에 완료된 기능의 수
        while(progresses[idx] + (speeds[idx] * time) >= 100){
            idx++;            
            if(idx > progresses.size()){
                break;
            }
            count++;
        }
        
        if(count != 0){
            answer.push_back(count);    
        }
    }
    
    return answer;
}