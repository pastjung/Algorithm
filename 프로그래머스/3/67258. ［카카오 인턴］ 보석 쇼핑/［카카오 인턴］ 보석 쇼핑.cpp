#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    int size = gems.size();
    vector<int> answer = {1, size};
    
    unordered_map<string, int> jewels;
    for(string gem : gems){
        jewels[gem] = 0;
    }
    
    int start = 0, kinds = 0;
    for(int end = 0; end < gems.size(); end++){
        if(jewels[gems[end]] == 0){
            kinds++;
        }
        jewels[gems[end]]++;
        
        while(jewels.size() == kinds){
            if(end - start < answer[1] - answer[0]){
                answer[0] = start + 1;
                answer[1] = end + 1;
            }
            
            jewels[gems[start]]--;
            if(jewels[gems[start]] == 0){
                kinds--;
            }
            start++;
        }
    }
    
    return answer;
}