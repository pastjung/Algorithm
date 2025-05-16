#include <iostream>
using namespace std;
typedef long long ll;

const int MAX = 4000000;
const int MOD = 1000000007;

ll fact[MAX + 1];  // factorial 배열

// 거듭제곱 (a^b % MOD) - 분할 정복
ll power(ll a, ll b) {
    ll result = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

// 모듈러 역원 (페르마의 소정리 이용)
ll modInverse(ll a) {
    return power(a, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    // 팩토리얼 미리 계산
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ll numerator = fact[n];                     // n!
    ll denominator = (fact[k] * fact[n - k]) % MOD;  // k! * (n-k)!
    ll result = (numerator * modInverse(denominator)) % MOD;

    cout << result << '\n';
    return 0;
}
