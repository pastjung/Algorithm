#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> cm : commands){
        vector<int> temp(array.begin() + cm[0] - 1, array.begin() + cm[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[cm[2] - 1]);
    }
    
    return answer;
}