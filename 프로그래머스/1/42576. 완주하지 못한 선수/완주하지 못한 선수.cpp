#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int N = completion.size();
    
    stable_sort(participant.begin(), participant.end());
    stable_sort(completion.begin(), completion.end());
    
    for(int i = 0; i < N; i++){
        if(participant[i] != completion[i]){
            return participant[i];
        }
    }
    return participant[N];
}