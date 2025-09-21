#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0;
    for (int j = 0; j < B.size(); j++){
        if (A[i] < B[j]){
            i++;
            answer++;
        }
    }
    return answer;
}