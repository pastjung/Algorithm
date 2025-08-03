#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 정렬 기준
bool cmp(int a, int b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    // 두 문자열의 합이 더 큰쪽을 기준으로 정렬
    sort(numbers.begin(), numbers.end(), cmp);
    
    // 정렬된 값으로 문자열 생성
    for(int number : numbers){
        answer += to_string(number);
    }
    
    // 최종 숫자가 0일 경우
    if(answer[0] == '0'){
        answer = "0";    
    }
    
    return answer;
}