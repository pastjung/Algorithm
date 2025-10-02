#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    
    stack<int> s;               // 삭제된 행을 저장할 스택
    vector<int> prev(n, 0);     // 이중 연결 리스트 (각 행의 이전 행의 위치를 저장)
    vector<int> next(n, 0);     // 이중 연결 리스트 (각 행의 다음 행의 위치를 저장)
    
    // 이중 연결 리스트 초기 설정
    for(int i = 0; i < n; i++){
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    
    int cur = k;
    for(string str : cmd){
        if(str[0] == 'U'){
            int move = stoi(str.substr(2));
            for(int i = 0; i < move; i++){
                cur = prev[cur];
            }
        } else if(str[0] == 'D'){
            int move = stoi(str.substr(2));
            for(int i = 0; i < move; i++){
                cur = next[cur];
            }
        } else if(str[0] == 'C'){
            s.push(cur);
            
            // 현재 행 삭제
            if(prev[cur] != -1){
                next[prev[cur]] = next[cur];
            }
            if(next[cur] != n){
                prev[next[cur]] = prev[cur];   
            }
            
            // 현재 행의 다음 행이 없는 경우 -> 이전 행을 현재 행으로 설정
            if(next[cur] == n){
                cur = prev[cur];
            } else{
                cur = next[cur];
            }
        } else if(str[0] == 'Z'){
            if(s.empty()){
                continue;
            }
            
            // stack의 top을 복구
            int temp = s.top();
            s.pop();
            
            // 이중 연결 리스트 재연결
            if(prev[temp] != -1){
                next[prev[temp]] = temp;
            }
            if(next[temp] != n){
                prev[next[temp]] = temp;   
            }
        }
    }
    
    // 삭제된 행 찾기
    while(!s.empty()){
        answer[s.top()] = 'X';
        s.pop();
    }
    
    return answer;
}