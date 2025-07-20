#include<string>
#include<stack>
using namespace std;

int solution(string s) {
    int answer = 0;
		
    // 왼쪽 짝을 저장할 stack 선언
    stack<char> ss;

    // stack의 top과 s의 char를 비교해서 짝이 있는지 확인
    for(char c : s){
        if(ss.empty()){
            ss.push(c);    // stack이 비어있는 경우 -> push()
        } else if(ss.top() == c){
            ss.pop();      // top과 c가 동일한 경우 -> pop()
        } else{ 
            ss.push(c);    // top과 c가 다른 경우 -> push()
        }
    }

    // stack이 비어있는 경우 -> answer = 1
    if(ss.empty()){
        answer = 1;
    }

    return answer;
}