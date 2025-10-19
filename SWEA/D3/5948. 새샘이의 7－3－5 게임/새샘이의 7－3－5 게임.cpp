#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n = 7;
int r = 3;

void dfs(const vector<int>& arr, set<int>& iSum, int sum, int cur, int times){
    if(times == r){
        iSum.insert(sum);
        return;
    }

    for(int i = cur; i < n; i++){
        dfs(arr, iSum, sum + arr[i], i + 1, times + 1);
    }
}

int solution(vector<int>& arr){
    set<int> iSum;
    sort(arr.begin(), arr.end(), greater<>());

    dfs(arr, iSum, 0, 0, 0);

    auto it = iSum.rbegin();
    advance(it, 4);
    
    return *it;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << '#' << i << ' ' << solution(arr) << '\n';
    }
    
    return 0;
}