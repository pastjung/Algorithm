#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> method1 = { 1, 2, 3, 4, 5 };
    vector<int> method2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> method3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    int answer1 = 0, answer2 = 0, answer3 = 0; // 정답 개수
    
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == method1[i % method1.size()]){
            answer1++;
        }
        
        if(answers[i] == method2[i % method2.size()]){
            answer2++;
        }
        
        if(answers[i] == method3[i % method3.size()]){
            answer3++;
        }
    }
    
    int maxAnswer = max({answer1, answer2, answer3});
    if (answer1 == maxAnswer) answer.push_back(1);
    if (answer2 == maxAnswer) answer.push_back(2);
    if (answer3 == maxAnswer) answer.push_back(3);
    
    return answer;
}