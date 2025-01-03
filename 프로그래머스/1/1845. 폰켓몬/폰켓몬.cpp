#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;    
    int N = nums.size() / 2;
    
    unordered_set<int> isNums;
    for(int i = 0; i < nums.size(); i++){
        isNums.insert(nums[i]);
    }
    
    if(isNums.size() <= N){
        answer = isNums.size();
    } else {
        answer = N;
    }
    
    return answer;
}