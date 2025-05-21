#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int greedy(int L, vector<pair<int, int>>& pools){
    sort(pools.begin(), pools.end());

    int cnt = 0;
    int last = 0;
    for(auto [start, end] : pools){
        // 이미 덮여있는 경우 시작점 보정
        if(start < last) start = last;

        // 덮을 길이
        int length = end - start;
        if(length <= 0) continue;

        int count = (length + L -1) / L; // 올림
        cnt += count;
        last = start + count * L;
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, L;
    cin >> N >> L;

    vector<pair<int, int>> pools(N);
    for(int n = 0; n < N; n++){
        cin >> pools[n].first >> pools[n].second;
    }

    cout << greedy(L, pools) << '\n';
    return 0;
}