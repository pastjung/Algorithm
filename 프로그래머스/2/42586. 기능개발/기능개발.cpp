#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int max_day = 0;    // 작업의 배포 기준 관리
    for (int idx = 0; idx < progresses.size(); idx++){
        int day = (99 - progresses[idx]) / speeds[idx] + 1; // 작업 완료 일수

        // 배포 그룹 관리
        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else{
            answer.back()++;    
        }            
        if (max_day < day){
            max_day = day;
        }
    }

    return answer;
}