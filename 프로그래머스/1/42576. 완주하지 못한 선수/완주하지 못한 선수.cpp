#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // 해시 테이블 생성
    unordered_map<string, int> hash_map;
    
    // completion 추가
    for(string str : completion){
        hash_map[str]++;
    }
    
    // completion에서 participant를 제거
    for(string str : participant){
        // 해시 테이블에 값이 없는 경우
        if(hash_map.find(str) == hash_map.end()){
            answer = str;
            break;
        }
        
        // 해시 테이블의 값이 1인 경우 erase, 1보다 클 경우 ++
        if(hash_map[str] == 1){
            hash_map.erase(str);
        } else{
            hash_map[str]--;
        }
    }
    
    return answer;
}