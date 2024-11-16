#include<iostream>
#include<vector>
using namespace std;

// 가능한 모든 비트마스크 조합 탐색
/*
  	각 숫자는 비트로 표시했을 때 선택/비선택을 하는 방식으로 해석
    ex) bitmask = 5 -> 101 -> 첫 번째와 세 번째 재료를 선택 O, 두 번째 재료는 선택 X
    이때  1 << N == 2^N
    시간 복잡도 : O(2*N * N) -> 이 방법은 재료의 수가 많지 않은 문제에서 적합 & N이 커지면 시간이 급격하게 증가
*/
int func(vector<int> arr, int N, int K){
 	int count = 0;
    for (int bitmask = 0; bitmask < (1 << N); bitmask++){
     	int total = 0;  
        // 비트마스크의 각 비트마다 선택할 재료 확인
        for(int i = 0; i < N; i++){
         	if (bitmask & (1 << i)){
                // i 번째 재료 선택
                total += arr[i];
                
                // 이미 초과한 경우
                if(total > K) break;
            }
        }   
        // 총점이 K인 경우
       	if (total == K) count ++;
    }
    return count;
}

int main(){
 	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N, K;
        cin >> N >> K;
        vector<int> arr(N, 0);
        for(int j = 0; j < N; j++){
            cin >> arr[j];
        }
        cout << '#' << i << ' ' << func(arr, N, K) << '\n';
    }
    return 0;
}