#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    // A와 B 모두 오름차순 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int j = 0;
    // 투 포인터를 이용해 A의 가장 작은 수부터 차례대로 확인
    for(int i = 0; i < A.size() && j < B.size(); i++){
        // B에서 그 수보다 큰 최소한의 수를 매칭
        while(j < B.size() && B[j] <= A[i]){
            j++;
        }
        if(j < B.size()){
            answer++;
            j++;
        }
    }
        
    return answer;
}