#include<iostream>
#include<vector>
using namespace std;

void func(int N){
    vector<vector<int>> arr(N);
    arr[0].push_back(1);
    
    for(int i = 1; i < N; i++){
        arr[i].push_back(1);
        for(int j = 0; j < i - 1; j++){
         	int temp = arr[i - 1][j] + arr[i - 1][j+1];
            arr[i].push_back(temp);
        }
        arr[i].push_back(1);
    }
    
    for(int i = 0; i < N; i++){
     	for(int n : arr[i]){
            cout << n << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N;
        cin >> N;
        cout << "#" << i << '\n';
        func(N);
    }
    return 0;
}