#include <iostream>
#include <cmath>
using namespace std;

int solution(int x, int y) {
    long long dist = x * x + y * y;
    for(int k = 1; k <= 10; k++){
        long long num = 20 * k;
        if(dist <= num * num){
            return 11 - k;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        int N, x, y;
        cin >> N;
        int score = 0;
        for(int n = 0; n < N; n++){
            cin >> x >> y;
            score += solution(x, y);
        }
        cout << '#' << TC << ' ' << score << '\n';
    }
    return 0;
}