#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // 해시 테이블 생성
    unordered_set<string> hash_set;
    
    // phone_book의 전화번호를 길이별로 저장 ( 단, 본인은 제외 )
    for(string phone : phone_book){
        string num = "";
        for(char c : phone){
            num += c;
            if(phone != num){
                hash_set.insert(num);   
            }
        }
    }
    
    // 해시 테이블에 존재할 경우 false리턴
    for(string phone : phone_book){
        if(hash_set.find(phone) != hash_set.end()){
            answer = false;
            break;
        }
    }
    
    return answer;
}