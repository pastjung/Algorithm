#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// 문자열 분리
vector<string> sepStr(string str){
    vector<string> results;
    
    size_t s1 = str.find(' ');
    results.push_back(string(str, 0, s1));
    
    if(results[0] != "Leave"){
        size_t s2 = str.find(' ', s1 + 1);
        results.push_back(string(str, s1 + 1, s2 - s1 - 1));
        results.push_back(string(str, s2 + 1, str.size() - (s2 + 1)));  
    } else{
        results.push_back(string(str, s1 + 1, str.size() - (s1 + 1)));  
    }
    
    return results;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    // 유저 아이디, 닉네임을 관리할 해시 테이블 생성
    unordered_map<string, string> hash_map;
    
    // 명령어, id를 저장할 큐 생성 - Enter(1), Leave(2)만 저장
    queue<pair<int, string>> q;
    
    // record 확인
    for(string r : record){
        // 문자열 분리
        vector<string> str = sepStr(r);
        
        if(str[0] == "Enter"){
            hash_map[str[1]] = str[2];
            q.push({1, str[1]});
        } else if(str[0] == "Leave"){
            q.push({2, str[1]});
        } else if(str[0] == "Change"){
            hash_map[str[1]] = str[2];
        }
    }
    
    // 큐의 데이터 문자열 형태로 변환 후 answer에 저장
    while(!q.empty()){
        auto pair = q.front();
        q.pop();
        if(pair.first == 1){
            answer.push_back(hash_map[pair.second] + "님이 들어왔습니다.");
        } else{
            answer.push_back(hash_map[pair.second] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}