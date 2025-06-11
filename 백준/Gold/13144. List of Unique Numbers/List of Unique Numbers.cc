#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

long long list_of_unique_numbers(int N, vector<int>& arr){
    long long cnt = 0;

    unordered_set<int> s;
    int left = 0;
    for(int right = 0; right < N; right++){
        while(s.find(arr[right]) != s.end()){
            s.erase(arr[left]);
            left++;
        }
        s.insert(arr[right]);
        cnt += right - left + 1;
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    for(int n = 0; n < N; n++){
        cin >> arr[n];    
    }

    cout << list_of_unique_numbers(N, arr) << '\n';
    return 0;
}