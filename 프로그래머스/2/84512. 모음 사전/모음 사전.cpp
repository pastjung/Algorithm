#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Backtracking(string alpha, string current, vector<string>& dictionary){
    if(current.length() > 5){
        return;
    }
    
    if(!current.empty()){
        dictionary.push_back(current);
    }
    
    for (int i = 0; i < alpha.size(); i++) {
        Backtracking(alpha, current + alpha[i], dictionary);
    }
}

int solution(string word) {
    int answer = 0;
    
    vector<string> dictionary;
    string alpha = "AEIOU";
    
    // 모든 단어 사전 생성
    Backtracking(alpha, "", dictionary);
    
    // 사전 순으로 정렬
    sort(dictionary.begin(), dictionary.end());
    
    auto it = find(dictionary.begin(), dictionary.end(), word);
    answer = distance(dictionary.begin(), it) + 1;
    
    return answer;
}