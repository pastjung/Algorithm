#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> strMap;
    
    for(string str : completion){
        if(strMap.find(str) == strMap.end()){
            strMap.insert({str, 1});
        } else{
            strMap[str]++;
        }
        
    }
    
    // find() : 요소가 존재하면 해댱 요소를, 존재하지 않으면 end() 반복자를 반환
    for(string str : participant){
        if(strMap.find(str) == strMap.end()){
            answer = str;
            break;
        } else {
            strMap[str]--;
            if(strMap[str] < 0){
                answer = str;
                break;
            }
        }
    }
    return answer;
}