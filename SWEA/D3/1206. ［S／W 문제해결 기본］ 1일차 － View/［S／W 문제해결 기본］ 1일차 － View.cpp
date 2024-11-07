#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(int N){
    vector<int> arr(N, 0);
    int count = 0;
 	for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    for(int i = 2; i < N - 2; i++){
    	int m = max(max(arr[i-2], arr[i-1]), max(arr[i+1], arr[i+2]));
        if(m < arr[i]) count += arr[i] - m;   
    }
    return count;
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