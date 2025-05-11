#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1;
    long long right = 1000000000 * times.size();
    long long answer = right;
    
    while(left <= right){
        long long mid = ( left + right ) / 2;
        
        // mid 시간 동안 처리 가능한 사람 수 계산
        long long total = 0;
        for(int time : times){
            total += mid / time;
        }
        
        if(total >= n){
            answer = mid;
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    
    return answer;
}