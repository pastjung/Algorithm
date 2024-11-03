#include <iostream>
#include <vector>
using namespace std;

long long func(vector<long long> arr){
    long long profit = 0;
    long long max = arr[arr.size() - 1];

    for(int i = arr.size() - 1; i >= 0; i--){
        if(max < arr[i]){
            max = arr[i];
        }else{
            profit += max - arr[i];
        }
    }    
    return profit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        vector<long long> arr;
        int N;
        cin >> N;
        for(int i = 1; i <= N; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }     
        cout << "#" << i << ' ' << func(arr) << "\n";
    }
    return 0;
}