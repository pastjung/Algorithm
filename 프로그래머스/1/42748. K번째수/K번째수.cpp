#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> command : commands){
        vector<int> arr(array.begin() + (command[0] - 1), array.begin() + command[1]);
        sort(arr.begin(), arr.end());
        answer.push_back(arr[command[2] - 1]);
    }
    
    return answer;
}