#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size() / 2;
    
    unordered_set<int> isNums;
    for(int i : nums){
        isNums.insert(i);
    }
    
    if(isNums.size() <= N){
        answer = isNums.size();
    } else {
        answer = N;
    }    
    
    return answer;
}