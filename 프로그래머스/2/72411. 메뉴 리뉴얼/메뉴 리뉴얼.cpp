#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 조합 생성 함수 ( 문자열, 선택할 메뉴 수 )
void makeComb(string& order, string comb, int idx, int targetLen, unordered_map<string, int>& courseMap){
    if (comb.size() == targetLen) {
        courseMap[comb]++;
        return;
    }
    for (int i = idx; i < order.size(); ++i) {
        makeComb(order, comb + order[i], i + 1, targetLen, courseMap);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // 코스가 등장할 횟수를 기록할 map 생성 (문자열의 크기별로 따로 저장)
    unordered_map<string, int> courseMap[11];
    
    // 손님 및 course의 개수 별 조합 생성
    for(string order : orders){
        // 문자열 정렬
        sort(order.begin(), order.end());
        for(int len : course){
            if (order.size() < len) continue;
            makeComb(order, "", 0, len, courseMap[len]);
        }
    }
    
    // map의 value가 가장 큰 코스를 answer에 추가 ( 중복 포함 )
    for(int n : course){
        int maxCount = 0;
        vector<string> courseCom;
        for(auto pair : courseMap[n]){
            if(pair.second >= 2 && pair.second > maxCount){
                maxCount = pair.second;
                courseCom.clear();
                courseCom.push_back(pair.first);
            } else if(pair.second == maxCount){
                courseCom.push_back(pair.first);
            }
        }
        for(string str : courseCom){
            answer.push_back(str);
        }
    }
    
    // answer 오름차순 정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}