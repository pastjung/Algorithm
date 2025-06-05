#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> lines(N);
    for (int i = 0; i < N; ++i) {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end()); // A 기준 정렬

    vector<int> lis; // B 기준 LIS 수행
    for (int i = 0; i < N; ++i) {
        int b = lines[i].second;
        auto it = lower_bound(lis.begin(), lis.end(), b);
        if (it == lis.end()) lis.push_back(b);
        else *it = b;
    }

    cout << N - lis.size() << "\n"; // 제거해야 할 전깃줄 수
    return 0;
}
