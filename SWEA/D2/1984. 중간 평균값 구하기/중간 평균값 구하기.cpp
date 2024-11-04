#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int func(vector<int> arr){
    int sum = 0;
    stable_sort(arr.begin(), arr.end());
    for(int i = 1; i <= 8; i++){
     	sum += arr[i];   
    }
    return round( sum / 8.0 );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        vector<int> arr;
        for(int j = 0; j < 10; j++){
            int temp;
            cin >> temp;
                arr.push_back(temp);
        }
        cout << '#' << i << ' ' << func(arr) << '\n';
    }
    return 0;
}