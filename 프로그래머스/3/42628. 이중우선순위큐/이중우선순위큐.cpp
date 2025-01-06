#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> doublePriorityQueue;
    
    for(string str : operations){
        char command = str[0];
        int num = stoi(str.substr(2, str.length() - 2));
        
        if(command == 'I'){
            // 숫자 삽입
            doublePriorityQueue.push_back(num);
            
            // 정렬
            stable_sort(doublePriorityQueue.begin(), doublePriorityQueue.end());
            
        } else if(command == 'D'){
            // 큐가 비어 있는 경우
            if(doublePriorityQueue.empty()){
                continue;
            }
            
            if(num == 1){
                // 최댓값 삭제
                doublePriorityQueue.pop_back();
            } else {
                // 최솟값 삭제
                doublePriorityQueue.erase(doublePriorityQueue.begin());
            }
        }
    }
    
    // 큐가 비어있는 경우
    if(doublePriorityQueue.empty()){
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(doublePriorityQueue.back());
        answer.push_back(doublePriorityQueue.front());
    }
    
    return answer;
}