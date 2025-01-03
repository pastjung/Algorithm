#include <vector>
#include <set>
using namespace std;

// key : value = 번호 : 순서
int solution(vector<int> nums)
{
    int answer = 0;    
    int N = nums.size() / 2;
    
    set<int> isNums;
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