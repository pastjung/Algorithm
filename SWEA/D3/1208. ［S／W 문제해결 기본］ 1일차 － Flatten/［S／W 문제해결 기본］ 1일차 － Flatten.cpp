#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(int N){
 	vector<int> arr(100);
    for(int i = 0; i < 100; i++) cin >> arr[i];
    stable_sort(arr.begin(), arr.end(), greater<int>());
    
    while(N--){
        arr[0]--;
        arr[99]++;
        stable_sort(arr.begin(), arr.end(), greater<int>());
    }
    return arr[0] - arr[99];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 1; i <= 10; i++){
        int N;
        cin >> N;
        cout << '#' << i << ' ' << func(N) << '\n';
    }
    return 0;
}