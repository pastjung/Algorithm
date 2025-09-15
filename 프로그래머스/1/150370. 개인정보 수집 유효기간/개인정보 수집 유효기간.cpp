#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

/* 문제 분석
- 입력 데이터 : O(N^3) 알고리즘까지 사용 가능
    - 오늘 날짜 : string
    - 약관 종류 terms : 각각 유효 기간 존재(유효기간 종료 후 파기) -> string(약관, 기간)
        - 유효 기간은 개월 단위 ( 1 ~ 100 )
        - 최대 20개
    - 개인정보 privacies : "수집 일자, 약관 종류"
        - 최대 100개
- 핵심 키워드 :
    - string 데이터로 날짜 데이터 입력 -> split 함수로 분리
    - 각 privacies에 terms의 기간을 더해서 today와 비교해서 작은 값들 반환
- 시간 복잡도 : O(N)
    - string 데이터로 날짜 데이터 입력 -> split 함수로 분리 => O(N)
    - 각 privacies에 terms의 기간을 더해서 today와 비교해서 작은 값들 반환 => O(N)
*/

// split 함수
vector<string> split(string str, char c){
    vector<string> answer;
    stringstream ss(str);
    string token;
    
    while(getline(ss, token, c)){
        answer.push_back(token);
    }
    return answer;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string, int> terms_table;    // terms를 저장할 해시 테이블
    
    // 오늘 날짜
    vector<string> day = split(today, '.');    // 오늘 날짜(년, 월, 일)
    vector<int> iDay;
    for(string d : day){
        iDay.push_back(stoi(d));
    }
    
    // 약관 저장
    for(string term : terms){
        vector<string> t = split(term, ' ');
        terms_table[t[0]] = stoi(t[1]);
    }
    
    // privacies + 유효 기간 < today인 개인 정보 확인
    for(int i = 0; i < privacies.size(); i++){
        // 해당 개인 정보를 ' '를 기준으로 분리 -> 수집 일자, 약관
        vector<string> s = split(privacies[i], ' ');
        
        // 수집 일자 + 유효 기간 결과 저장
        vector<string> privacy = split(s[0], '.');
        vector<int> iPrivacy;
        for(string p : privacy){
            iPrivacy.push_back(stoi(p));
        }
        iPrivacy[1] += terms_table[s[1]];
        if(iPrivacy[1] > 12){
            iPrivacy[0] += (iPrivacy[1] - 1) / 12;
            iPrivacy[1] = (iPrivacy[1] - 1) % 12 + 1;
        }
        
        // 수집 일자 + 유효 기간 < today인 개인 정보 저장
        if (iPrivacy[0] < iDay[0] ||
           (iPrivacy[0] == iDay[0] && iPrivacy[1] < iDay[1]) ||
           (iPrivacy[0] == iDay[0] && iPrivacy[1] == iDay[1] && iPrivacy[2] <= iDay[2])) {
            answer.push_back(i + 1);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}