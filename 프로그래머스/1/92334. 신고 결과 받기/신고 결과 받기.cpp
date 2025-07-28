#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    // 유저 정보를 저장할 해시 테이블 생성 및 유저 정보 추가
    unordered_map<string, int> users;
    for(int i = 0; i < id_list.size(); i++){
        users[id_list[i]] = i;
    }
    
    // 신고한 유저를 저장할 해시 테이블 배열 생성
    vector<unordered_set<int>> hash_map(id_list.size());
    
    // 신고 받은 횟수를 저장하기 위한 배열 생성
    vector<int> repo(id_list.size(), 0);
    
    // report를 set에 저장 -> 정렬 및 중복 제거
    set<string> report_set(report.begin(), report.end());
    
    // 신고 내용 처리
    for(string str : report_set){
        size_t space = str.find(' ');
        string s1(str, 0, space);                        // 신고자
        string s2(str, space + 1, str.size() - space);   // 신고 대상자
        
        // 신고 유저 추가
        hash_map[users[s1]].insert(users[s2]);
        
        // 신고 받은 횟수 추가
        repo[users[s2]]++;
    }
    
    // 메일 받는 횟수 계산
    for(int id = 0; id < id_list.size(); id++){
        for(int user : hash_map[id]){
            if(repo[user] >= k){
                answer[id]++;
            }
        }
    }
    
    return answer;
}