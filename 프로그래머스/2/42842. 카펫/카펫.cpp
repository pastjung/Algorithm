#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

// n * m = brown + yellow
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown + yellow;   // 모든 카펫의 개수    
    for(int i = 3; i < sum / 2; i++) {
        if(sum % i == 0 && (i - 2) * (sum / i - 2) == yellow) {    
            answer.push_back(max(i, sum / i));
            answer.push_back(min(i, sum / i));
            break;
        }
    }
    
    return answer;
}