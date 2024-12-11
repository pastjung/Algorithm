#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(int N){
    // 단조 증가인지 판단
    int last = N % 10;
    while(N >= 10){
        N /= 10;
        int pre = N % 10;
        if(pre > last) return false;
        last = pre;
    }
    return true;
}

int func(vector<int> arr, int N){
    int maxN = -1;
    for(int i = 0; i < N; i++){
     	for(int j = i + 1; j < N; j++){
            int product = arr[i] * arr[j];
         	if(check(product)) maxN = max(maxN, product);
        }
    }
    
 	return maxN;   
}

int main(){
 	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T, N;
    cin >> T;
    for(int t = 1; t <= T; t++){
     	cin >> N;   
        vector<int> arr(N, 0);
        for(int n = 0; n < N; n++) cin >> arr[n];
        cout << '#' << t << ' ' << func(arr, N) << '\n';
    }
    return 0;
}