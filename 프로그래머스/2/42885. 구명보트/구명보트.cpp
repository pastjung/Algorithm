#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // 무게를 기준으로 정렬
    sort(people.begin(), people.end());
    
    int big = people.size() - 1;    // 무게가 높은 쪽의 index
    int small = 0;                  // 무게가 낮은 쪽의 index
    
    // 모든 사람을 구조할 때까지 반복
    while(small <= big){
        answer++;
        
        // 1명만 남은 경우
        if(small == big) break;
        
        // 무게가 낮은 쪽 사람도 탈 수 있는 경우
        if(people[small] + people[big] <= limit){
            small++;
        }
        
        // 무게가 높은 쪽 태우기
        big--;
    }
    
    return answer;
}