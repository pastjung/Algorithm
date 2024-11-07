#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void func(int N){
    vector<int> arr(N);
    int count = 0;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(arr[i] < 0) arr[i] *= -1;
    }
    stable_sort(arr.begin(), arr.end());
    for(int v : arr){
     	   if(arr[0] == v) count++;
    }
    cout << arr[0] << ' ' << count << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N;
        cin >> N;
        cout << '#' << i << ' ';
        func(N);
    }
    return 0;
}