#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    
    // answer -> n개의 'O'을 가진 문자열로 재할당
    answer.assign(n, 'O');
    
    // 삭제된 인덱스를 저장할 스택 선언
    stack<int> deleted;
    
    // 각각의 위치에서의 이전 위치와 다음 위치를 저장할 배열 선언
    vector<int> prev(n), next(n);
    
    // 이중 연결 리스트 초기화
    for (int i = 0; i < n; i++) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;
    
    // cmd 명령어 수행
    for (string c : cmd) {
        char op = c[0];
        if (op == 'U') {
            int x = stoi(c.substr(2));  // 이동할 거리
            while (x--) {
                k = prev[k];
            }
        } else if (op == 'D') {
            int x = stoi(c.substr(2));  // 이동할 거리
            while (x--) {
                k = next[k];
            }
        } else if (op == 'C') {
            // 현재 위치 삭제
            deleted.push(k);
            answer[k] = 'X';
            
            // 이중 연결 리스트 조정
            if (prev[k] != -1) {
                next[prev[k]] = next[k];
            }
            if (next[k] != -1) {
                prev[next[k]] = prev[k];
            }
            
            // 현재 위치 수정
            k = (next[k] != -1) ? next[k] : prev[k];
        } else if (op == 'Z') {
            // 마지막 삭제 내역 복원
            int r = deleted.top(); 
            deleted.pop();
            answer[r] = 'O';
            
            // 이중 연결 리스트 조정
            if (prev[r] != -1) {
                next[prev[r]] = r;
            }
            if (next[r] != -1) {
                prev[next[r]] = r;
            }
        }
    }
    
    return answer;
}