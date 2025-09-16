#include <string>
#include <vector>
using namespace std;

/* 문제 분석
- 문제 설명
    - 문자열 x를 최대한 사전 순으로 앞에 오고자 함 -> 110을 뽑아서 임의의 위치에 다시 삽입
    - 각 문자열에 대해서 변형해서 만들 수 있는 문자열 중 사전 순으로 가장 앞에 오는 문자열을 배열에 담아 반환
- 입력 데이터
    - 0과 1로 이루어진 문자열x의 배열 s -> 최대 100만 -> O(NlogN)알고리즘 사용 가능
    - s의 각 원소 x : 100만
- 핵심 키워드
    - 110을 뽑아서 임의의 위치에 다시 삽입 -> string의 find, erase, insert
        - 모든 위치에 값을 넣어보면서 가장 작은 값 찾기 -> 시간 초과
        - 맨 처음에 나오는 111 앞에 배치?
    - 110을 뽑는 과정은 여러번 해도 되는듯? -> 함수로 만들기
    - 사전 순 비교 : >, <
    - 110이 여러 개 있다면?
        - 1 110 0 110 1
        -> 어차피 앞에 110을 수행한 다음 다음 110을 수행하기 때문에 상관 없을듯?
*/

// 110 제거 함수
string remove110(const string& x, int& n110){
    string s;
    for(char c : x){
        s.push_back(c);
        if(s.size() >= 3){
            int n = s.size();
            if(s[n - 3] == '1' && s[n - 2] == '1' && s[n - 1] == '0'){
                s.pop_back();
                s.pop_back();
                s.pop_back();
                n110++;
            }
        }
    }
    return s;
}

string repeat110(int n){
    string s = "";
    for(int i = 0; i < n; i++){
        s += "110";
    }
    return s;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    // s의 각 원소마다 사전 순 변형
    for(string x : s){
        if(x.size() <= 3){
            answer.push_back(x);
            continue;
        }
        
        // 110 위치 전부 탐색
        int n110 = 0;
        string x110 = remove110(x, n110);
        
        int pos = x110.find("111");    // 가장 먼저 나오는 111 위치 탐색
        
        // 111 위치가 없는 경우 -> 가장 마지막에 나오는 0 위치 탐색
        if(pos == string::npos){
            int lastZero = x110.rfind('0');
            if(lastZero != string::npos){
                pos = lastZero + 1;
            } else{
                pos = 0;
            }
        }
        
        // n110개의 "110"을 pos 위치에 배치
        x110.insert(pos, repeat110(n110));
        answer.push_back(x110);
    }
    
    return answer;
}