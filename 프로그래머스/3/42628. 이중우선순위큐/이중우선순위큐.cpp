#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> doublePriorityQueue;
    
    for(string str : operations){
        char command = str[0];
        int num = stoi(str.substr(2, str.length() - 2));
        
        if(command == 'I'){
            // 숫자 삽입
            doublePriorityQueue.insert(num);            
        } else if(command == 'D'){
            // 큐가 비어 있는 경우
            if(doublePriorityQueue.empty()){
                continue;
            }
            
            if(num == 1){
                // 최댓값 삭제
                // 이때 erase는 const_iterator 또는 특정 값만 받기 때문에 역방향 반복자를 반환하는 rbegin()은 사용 불가
                doublePriorityQueue.erase(--doublePriorityQueue.end()); 
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
        answer.push_back(*doublePriorityQueue.rbegin());
        answer.push_back(*doublePriorityQueue.begin());
    }
    
    return answer;
}