#include<string>
#include<queue>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    queue<char> que;
    for(char c : s){
        if(c == '('){
            que.push('(');
        } else{
            if(que.empty()){
                answer = false;
                break;
            } else {
                que.pop();   
            }
        }
    }
    
    if(!que.empty()){
        answer = false;
    }

    return answer;
}