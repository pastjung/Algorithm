#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, (int)gems.size()};
    int minLength = gems.size();
    
    // 모든 보석의 종류 파악 -> unordered_map<string, int>
    unordered_map<string, int> jewels;
    
    for(string gem : gems){
        jewels[gem] = 0;
    }
    
    // 투포인터: 가장 짧은 구간의 길이 확인
    int count = 0;
    for(int start = 0, end = 0; end < gems.size(); end++){
        if(jewels[gems[end]] == 0){
            count++;
        }
        jewels[gems[end]]++;
        
        while(count == jewels.size()){
            if(end - start + 1 < minLength){
                answer = {start + 1, end + 1};
                minLength = end - start + 1;
            }
            
            jewels[gems[start]]--;
            if(jewels[gems[start]] == 0){
                count--;
            }
            start++;
        }
    }
    
    return answer;
}