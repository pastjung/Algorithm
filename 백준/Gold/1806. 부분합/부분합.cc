#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, S;
    cin >> N >> S;

    vector<int> arr(N, 0);
    for(int i = 0; i < N; i++) cin >> arr[i];

    int left = 0, sum = 0;
    int minLength = N + 1;

    for(int right = 0; right < N; right++){
        sum += arr[right];

        while(sum >= S){
            minLength = min(minLength, right - left + 1);
            sum -= arr[left++];
        }
    }

    if(minLength == N + 1) cout << 0 << "\n";
    else cout << minLength << "\n";
    
    return 0;
}