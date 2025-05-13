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

    vector<long long> arr(N, 0);
    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<long long> answer(3, 0);
    long long minSum = 3000000000;
    for(int left = 0; left < N - 2; left++){
        int mid = left + 1, right = N - 1;
        
        while(mid < right){
            long long sum = arr[left] + arr[mid] + arr[right];
            
            if(abs(sum) < minSum){
                answer[0] = arr[left];
                answer[1] = arr[mid];
                answer[2] = arr[right];
                minSum = abs(sum);
            }
    
            if(sum == 0) break;
            else if(sum > 0) right--;
            else mid++;
        }    
    }
    
    for(long long i : answer){
        cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}