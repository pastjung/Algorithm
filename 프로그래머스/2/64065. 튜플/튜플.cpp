#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
using namespace std;

// 문자열 분리 함수
vector<int> split(string str, char c){
    vector<int> answer;
    
    // 문자 c와 숫자만 추가
    string s = "";
    for(char cc : str){
        if(isdigit(cc) || cc == c){
            s += cc;
        }
    }
    
    // 문자 c를 기준으로 문자열 분리
    stringstream ss(s);
    string token;
    while(getline(ss, token, c)){
        answer.push_back(stoi(token));
    }
    
    return answer;
}

// 정렬 기준 함수 : 빈도수(value)가 높은 숫자가 우선순위가 더 높음
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    // 문자열 분리 : 숫자만 남긴 배열
    vector<int> ss = split(s, ',');
    
    // s의 숫자의 빈도수를 저장할 해시 테이블 생성 및 초기화 ( 숫자 : 빈도수 )
    unordered_map<int, int> hash_table;
    for(int n : ss){
        hash_table[n]++;
    }
    
    // 해시 테이블을 배열로 변환
    vector<pair<int, int>> sorted_arr(hash_table.begin(), hash_table.end());
    
    // 빈도수를 기준으로 정렬
    sort(sorted_arr.begin(), sorted_arr.end(), cmp);
    
    // 정렬된 배열의 순서대로 튜플 채우기
    for(auto [num, count] : sorted_arr){
        answer.push_back(num);
    }
    
    return answer;
}