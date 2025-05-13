#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N, 0);
    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int answer = 0;
    for(int i = 0; i < N; i++){
        int target = arr[i];
        int left = 0, right = N - 1;

        while(left < right){
            if(left == i){
                left++;
                continue;
            }
            if(right == i){
                right--;
                continue;
            }

            int sum = arr[left] + arr[right];

            if(sum == target) {
                answer++;
                break;
            } else if(sum < target) left++;
            else right--;
        }
    }

    cout << answer << '\n';
    
    return 0;
}