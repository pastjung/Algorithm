#include <string>
#include <vector>
#include <queue>
#include<iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap(scoville.begin(), scoville.end());
    
    while(minHeap.top() < K){
        if(minHeap.size() == 1){
            answer = -1;
            break;
        }
        
        int min = minHeap.top();
        minHeap.pop();
        int secondMin = minHeap.top();
        minHeap.pop();
        
        minHeap.push(min + ( 2 * secondMin ));
        answer++;
    }
    
    return answer;
    
}