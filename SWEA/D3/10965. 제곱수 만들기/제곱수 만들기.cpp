#include <iostream>
#include <cmath>
using namespace std;

int solution(int A) {
    int answer = 1;
    for (int i = 2; i * i <= A; i++) {
        int count = 0;
        while (A % i == 0) {
            A /= i;
            count++;
        }
        // 홀수 횟수로 등장한 소인수는 한 번 더 곱해줘야 함
        if (count % 2 == 1) {
            answer *= i;
        }
    }
    // A가 남아있다면 소수 (지수 1)
    if (A > 1) {
        answer *= A;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        int A;
        cin >> A;
        cout << '#' << TC << ' ' << solution(A) << '\n';
    }
    return 0;
}