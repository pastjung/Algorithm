#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeroCount = 0;
    int count = 0;
    
    // lottos의 값을 win_nums와 비교
    for(int lotto : lottos){
        // lotto == 0인 경우 -> zeroCount++
        if(lotto == 0){
            zeroCount++;
            continue;
        }
        // lotto == win_num인 경우in_num인 경우 -> count++
        if(find(win_nums.begin(), win_nums.end(), lotto) != win_nums.end()){
            count++;
        }
    }
    
    if(count == 0){
        if(zeroCount == 0){
            answer.push_back(6 - zeroCount);    
        } else {
            answer.push_back(7 - zeroCount);
        }
        answer.push_back(6);
    } else {
        answer.push_back(7 - count - zeroCount);
        answer.push_back(7 - count);
    }
    
    return answer;
}