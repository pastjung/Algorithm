#include <iostream>
#include <vector>
using namespace std;

// key : value = 번호 : 순서
int solution(vector<int> nums)
{
    int answer = 0;    
    int N = nums.size() / 2;
    
    vector<bool> isNums(200000, false);
    for(int n : nums) {
        isNums[n] = true;
    }
    
    for(bool isNum : isNums){
        if(isNum) answer++;
    }
    
    if(answer <= N) {
        return answer;
    }
    else{
        return N;
    }
}