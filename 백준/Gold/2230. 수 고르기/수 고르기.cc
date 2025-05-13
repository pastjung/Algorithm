#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N, 0);
    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int left = 0, answer = INT_MAX;

    for(int right = 0; right < N; right++){      
        while (arr[right] - arr[left] >= M) {
            if(left > right) break;
            answer = min(answer, arr[right] - arr[left]);
            left++;
        }
    }

    cout << answer << '\n';
    
    return 0;
}