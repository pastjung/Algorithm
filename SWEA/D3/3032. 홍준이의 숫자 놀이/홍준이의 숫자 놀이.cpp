#include <iostream>
using namespace std;

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        long long A, B, x, y;
        cin >> A >> B;

        long long g = extended_gcd(A, B, x, y);

        cout << "#" << tc << " ";
        if (g != 1) {
            cout << -1 << "\n";
        } else {
            cout << x << " " << y << "\n";
        }
    }

    return 0;
}