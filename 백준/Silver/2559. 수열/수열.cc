#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> arr(N, 0);
    for(int i = 0; i < N; i++) cin >> arr[i];

    int sum = 0;
    for(int i = 0; i < K; i++){
        sum += arr[i];
    }

    int left = 0, maxSum = sum;
    for(int right = K; right < N; left++, right++){
        sum -= arr[left];
        sum += arr[right];

        if(sum >= maxSum){
            maxSum = sum;
        }
    }
    cout << maxSum << "\n";
    
    return 0;
}