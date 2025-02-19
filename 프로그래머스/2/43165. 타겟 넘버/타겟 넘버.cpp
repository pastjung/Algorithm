#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int target, int number, int idx, int& answer){
    if(idx == numbers.size()){
        if(target == number) {
            answer++;
        }
        return;
    } 
    DFS(numbers, target, number + numbers[idx], idx + 1, answer);
    DFS(numbers, target, number - numbers[idx], idx + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, target, 0, 0, answer);
    return answer;
}