#include <string>

using namespace std;

int solution(string word) {
    string alpha = string("AEIOU");
    int answer = word.size();

    for(int i = 0, weight = 1; i < word.size(); i++, weight *= 5)
        answer += alpha.find(word[i]) * 781 / weight;

    return answer;
}