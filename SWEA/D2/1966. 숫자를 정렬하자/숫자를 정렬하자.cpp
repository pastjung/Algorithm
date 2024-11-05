#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N;
        cin >> N;
     	vector<int> arr(N);
        for(int j = 0; j < N; j++){
            cin >> arr[j];
        }
        stable_sort(arr.begin(), arr.end());
        cout << '#' << i << ' ';
        for(int v : arr){
            cout << v << ' ';
        }
        cout << '\n';
    }    
    return 0;
}