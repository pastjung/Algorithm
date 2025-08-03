#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int SIZE = 26;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    set<int> char_table;                    // 문자 정렬 테이블
    vector<set<string>> sort_table(SIZE);   // 계수 정렬 테이블
    
    // n번째 글자를 계수 정렬 테이블에 삽입
    for(string s : strings){
        char_table.insert(s[n] - 'a');
        sort_table[s[n] - 'a'].insert(s);
    }
    
    // 정렬된 값을 answer에 추가
    for(int c : char_table){
        for(string s : sort_table[c]){
            answer.push_back(s);
        }
    }
    
    return answer;
}