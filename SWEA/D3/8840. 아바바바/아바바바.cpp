#include <iostream>
using namespace std;

long long solution(long long L) {
    return (L - 1) * (L - 1) / 4;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        long long L;
        cin >> L;
        cout << '#' << TC << ' ' << solution(L) << '\n';
    }
    return 0;
}
