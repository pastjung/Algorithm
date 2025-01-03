#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> strSet;
    
    // Hash Table 생성
    for(string str : phone_book){
        strSet.insert(str);
    }
    
    // 각 전화번호가 다른 전화번호의 접두사인지 확인
    for(string phoneNum : phone_book){
        string preNum = "";
        for(int i = 0; i < phoneNum.size(); i++){
            preNum += phoneNum[i];
            if(strSet.find(preNum) != strSet.end() && preNum != phoneNum){
                answer = false;
                break;
            }
        }
        
    }
    
    return answer;
}