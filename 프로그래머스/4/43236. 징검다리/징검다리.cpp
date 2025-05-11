#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);  // 마지막 지점도 바위로 추가
    
    int left = 1;
    int right = distance; 
    int answer = 0;
    
    while(left <= right){
        int mid = ( left + right ) / 2; // 최소 거리 후보
        int prev = 0;
        int removed = 0;
        
        for(int i = 0; i < rocks.size(); i++){
            if(rocks[i] - prev < mid)   removed++;  // 최소 거리보다 작으면 바위 제거
            else prev = rocks[i];
        }
        
        if(removed > n) right = mid - 1;    // mid 간격을 유지하려면 바위를 너무 많이 제거해야 하므로 거리 줄이기
        else {
            answer = mid;
            left = mid + 1;
        }
    }
    
    return answer;
}