#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

/* 문제 분석
- 문제 설명
    - 0과 1로 이루어진 문자열을 이진 변환
        - x의 모든 0을 제거
        - x의 길이 c를 2진법으로 표현한 문자열로 변경
    - 문자열 s가 "1"이 될 때까지 반복 -> 이진 변환 횟수, 변환 과정에서 제거된 0의 개수 반환
- 입력 데이터
- 핵심 키워드
    -> 문자열 0제거 or 1의 개수 파악 -> count
    - 10진법 -> 2진법
*/

// 10진법 -> 2진법 변환 함수
string decimal_to_binary(int dec){
    if(dec == 0){
        return "0";
    }
    
    bitset<32> binary(dec);
    string result = binary.to_string();
    return result.substr(result.find('1'));
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int SIZE = s.size();
    
    // s가 "1"이 될 때까지 이진 변환 함수 반복
    while(s != "1"){
        int zero = count(s.begin(), s.end(), '0');
        int one = s.size() - zero;
        s = decimal_to_binary(one);
        
        answer[0]++;
        answer[1] += zero;
    }
    
    return answer;
}