#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(const vector<int>& arr){
    int n = arr.size();
    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
        int N;
        cin >> N;
        vector<int> arr(N, 0);

        for(int n = 0; n < N; n++){
            cin >> arr[n];
        }

        cout << '#' << t << ' ' << LIS(arr) << '\n';
    }
    return 0;
}