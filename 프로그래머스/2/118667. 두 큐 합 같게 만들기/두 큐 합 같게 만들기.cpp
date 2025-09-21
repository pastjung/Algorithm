#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int size = queue1.size();
    long long sum1 = 0, sum2 = 0;     // 각각 합
    
    deque<int> q1(queue1.begin(), queue1.end());
    deque<int> q2(queue2.begin(), queue2.end());
    
    for(int q : queue1) sum1 += q;
    for(int q : queue2) sum2 += q;
    
    // 두 합이 동일한지 확인
    if(sum1 == sum2) return 0;
    
    int count = 0;  // 시행 횟수
    
    while(count <= size * 3){
        count++;
        if(sum1 > sum2){
            int tmp = q1.front();
            q1.pop_front();
            sum1 -= tmp;
            sum2 += tmp;
            q2.push_back(tmp);
        } else{
            int tmp = q2.front();
            q2.pop_front();
            sum2 -= tmp;
            sum1 += tmp;
            q1.push_back(tmp);
        }
        
        if(sum1 == sum2) return count;
    }
    
    return answer;
}