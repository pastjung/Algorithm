#include <string>
#include <vector>
#include <algorithm>

#include<iostream>

using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNums;
    
    for(int num : numbers){
        strNums.push_back(to_string(num));
    }
    
    sort(strNums.begin(), strNums.end(), cmp);
    
    for(string num : strNums){
        answer += num;
    }
    
    if(answer[0] == '0'){
        answer = "0";
    }
    
    return answer;
}