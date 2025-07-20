#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> sums;
    
    int n = numbers.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            sums.insert(numbers[i] + numbers[j]);
        }
    }
    
    vector<int> answer(sums.begin(), sums.end());
    return answer;
}