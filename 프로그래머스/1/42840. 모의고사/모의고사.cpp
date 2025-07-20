#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 학생 답안 템플릿 선언
    vector<vector<int>> studentAnswers = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    // 학생 성적 배열 선언
    vector<int> studentScores(3, 0);
    
    // 점수 채점
    for(int i = 0; i < answers.size(); ++i){
        if(answers[i] == studentAnswers[0][i % 5]){
            studentScores[0]++;
        }
        if(answers[i] == studentAnswers[1][i % 8]){
            studentScores[1]++;
        }
        if(answers[i] == studentAnswers[2][i % 10]){
            studentScores[2]++;
        }
    }
    
    // 가장 높은 점수 추출
    int maxScore = *max_element(studentScores.begin(), studentScores.end());
    
    // 가장 높은 점수를 가진 학생 추출
    for(int i = 0; i < 3; ++i){
        if(maxScore == studentScores[i]){
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}