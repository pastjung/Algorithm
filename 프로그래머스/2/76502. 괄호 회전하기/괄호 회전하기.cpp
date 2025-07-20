#include <string>
#include <vector>
#include <stack>
using namespace std;

// 괄호가 올바른지 확인하는 함수
bool isValid(string s){
    stack<char> stack;
    
    for(char c : s){
        if(c == '(' || c == '[' || c == '{'){
            stack.push(c);
        } else {
            if(stack.empty()){
                return false;
            } else if(c == ')' && stack.top() == '('){
                stack.pop();
            } else if(c == ']' && stack.top() == '['){
                stack.pop();
            } else if(c == '}' && stack.top() == '{'){
                stack.pop();
            } else {
                return false;
            }
        }
    }
    
    return stack.empty();
}

int solution(string s) {
    int answer = 0;
    
    // 괄호를 회전하면서 확인해볼 string 변수 선언
    string tmpStr = s;
    
    // 올바른 괄호 문자열이 되는 횟수 계산
    for(char c : s){
	    // 올바른 문자열인 경우 1추가
        if(isValid(tmpStr)){
            answer++;
        }
        
	    // 괄호 회전
        tmpStr += tmpStr[0];
        tmpStr.erase(0, 1);
    }
    
    return answer;
}