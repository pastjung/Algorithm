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
    
    int left = 0, right = N - 1;
    int l = 0, r = N - 1, minSum = abs(arr[left] + arr[right]);
    while(left < right){       
        int sum = arr[left] + arr[right];
        
        if(abs(sum) < minSum){
            l = left;
            r = right;
            minSum = abs(sum);
        }

        if(minSum == 0) break;
        else if(sum > 0) right--;
        else left++;
    }
    
    cout << arr[l] << ' ' << arr[r] << "\n";
    
    return 0;
}