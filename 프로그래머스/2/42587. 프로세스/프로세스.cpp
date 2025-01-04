#include <string>
#include <vector>
#include <queue>
#include <utility>
#include<iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> processQueue; // { 위치 : 우선순위 }
    priority_queue<int> priorityQueue;
    
    for(int i = 0; i < priorities.size(); i++){
        processQueue.push({i, priorities[i]});
        priorityQueue.push(priorities[i]);
    }
    
    int num = 0;
    while(!processQueue.empty()){
        auto temp = processQueue.front();
        processQueue.pop();
        if(temp.second == priorityQueue.top()){
            priorityQueue.pop();
            num++;
            if(temp.first == location){
                answer = num;
                break;
            }
        } else {
            processQueue.push(temp);
        }
    }
    
    
    return answer;
}