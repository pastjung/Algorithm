#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> hash_map;
    
    // 종류별로 묶어서 종류의 개수 구하기
    for(vector<string> cloth : clothes){
        string clothType = cloth[1];
        
        if(hash_map.find(clothType) == hash_map.end()){
            hash_map.insert({clothType, 1});    
        } else{
            hash_map[clothType]++;
        }
    }
    
    // 각 의상을 0 or 1개 선택하는 경우의 수 : (종류1의 개수 + 1) * (종류2의 개수 + 1) ... 
    for(auto it = hash_map.begin(); it != hash_map.end(); it++){
        answer *= (it->second + 1);
    }
        
    // 모든 종류에서 아무것도 선택하지 않는 경우 제외
    return answer - 1; 
}