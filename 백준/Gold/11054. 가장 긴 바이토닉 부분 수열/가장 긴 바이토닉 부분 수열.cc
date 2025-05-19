#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N, 0);
    for(int n = 0; n < N; n++){
        cin >> arr[n];
    }

    vector<int> leftDP(N, 1);   // 증가 수열
    vector<int> rightDP(N, 1);  // 감소 수열

    // 1. 왼쪽부터 LIS
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                leftDP[i] = max(leftDP[i], leftDP[j] + 1);
            }
        }
    }

    // 2. 오른쪽부터 LDS
    for(int i = N - 2; i >= 0; i--){
        for(int j = N - 1; j > i; j--){
            if(arr[j] < arr[i]){
                rightDP[i] = max(rightDP[i], rightDP[j] + 1);
            }
        }
    }

    // 3. 바이토닉 수열 길이 계산
    int answer = 0;
    for(int i = 0; i < N; i++){
        answer = max(answer, leftDP[i] + rightDP[i] - 1);
    }
    cout << answer << '\n';
    return 0;
}