#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

// 10진수 -> 2진수 변환 함수
string decimal_to_bianry(int num){
    bitset<32> binary(num);
    string binaryStr = binary.to_string();
    
    if(num == 0) return "0";
    return binaryStr.substr(binaryStr.find('1'));
}

// 이진 변환 함수
string transpose(string str){
    int oneCount = count(str.begin(), str.end(), '1');
    return decimal_to_bianry(oneCount);
}

vector<int> solution(string s) {
    vector<int> answer = {0, 0};
    
    // 문자열이 "1"이 될 때까지 이진 변환 반복
    while(s != "1"){
        answer[0]++;
        answer[1] += count(s.begin(), s.end(), '0');
        s = transpose(s);
    }
    
    return answer;
}