#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(vector<pair<int, int>> arr, int N, int L){
 	int max_taste_score = 0;
    
    // 가능한 모든 비트마스크 조합 탐색
    /*
    	각 숫자는 비트로 표시했을 때 선택/비선택을 하는 방식으로 해석
        ex) bitmask = 5 -> 101 -> 첫 번째와 세 번째 재료를 선택 O, 두 번째 재료는 선택 X
        이때  1 << N == 2^N
        시간 복잡도 : O(2*N * N ) -> 이 방법은 재료의 수가 많지 않은 문제에서 적합 & N이 커지면 시간이 급격하게 증가
    */
    for (int bitmask = 0; bitmask < (1 << N); bitmask++){
     	int total_taste = 0;
        int total_calories = 0;
        
        // 비트마스크의 각 비트마다 선택할 재료 확인
        for(int i = 0; i < N; i++){
         	if (bitmask & (1 << i)){
                // i 번째 재료 선택
                total_taste += arr[i].first;
                total_calories += arr[i].second;
            }
        }
        // 칼로리가 L 이하인 경우에만 맛 점수 갱신
        if (total_calories <= L){
        	max_taste_score = max(max_taste_score, total_taste);    
        }
    }
    
    return max_taste_score;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T, N, L;
    cin >> T;
    for(int i = 1; i <= T; i++){
    	cin >> N >> L;
        vector<pair<int,int>> arr(N, {0, 0});
     	for(int j = 0; j < N; j++){
        	cin >> arr[j].first >> arr[j].second;
    	}
        cout << '#' << i << ' ' << func(arr, N, L) << '\n';
    }
}