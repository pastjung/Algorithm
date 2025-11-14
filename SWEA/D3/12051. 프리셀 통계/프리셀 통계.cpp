#include <iostream>
#include <string>
using namespace std;

/* 문제 분석
- 문제 설명
    - 총 G판의 프리셀 게임
    - 오늘 D판의 프리셀 게임
    - 프리셀 게임 : 반드시 승패 존재
    - 오늘 승률 : PD ( D판 중 px판 승 )
    - 전체 승률 : PG ( G판 중 py판 승 )
    - G, D를 모름 ( 단, D <= N인 것은 앎 )
    - 결론: 적당한 G, D를 가지고 오늘과 같이 승률이 딱 떨어지는 값이 존재하는가?
- 입력 데이터
    - N : D의 최댓값
    - PD : 오늘 승률
    - PG : 전체 승률
- 핵심 키워드
    - 오늘 이긴 판 : x일 경우
        - x / D * 100 = PD ( D는 100의 약수 )
            => D = (x * 100) / PD
        - (x + y) / G * 100 = PG ( G는 100의 약수 )
            => G = (x + y) * 100 / PG
    -> 즉, G, D 모두 각자 해당하는 값의 약수여야지 정수가 나올 수 있음
    - PD or PG == 0인 경우, 전부 다 진 경우
    - N ≤ 10^15 -> O(logN) 알고리즘 사용

    - PD와 PG를 각각 100으로 소인수분해하여 남은 값들을 곱한 값이 N보다 클 경우 Broken, 작으면 Possible
*/

const string result[2] = {"Possible", "Broken"};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int solution(long long N, int PD, int PG){
    // 모순 케이스
    if (PG == 100 && PD != 100) return 1;
    if (PG == 0 && PD != 0) return 1;

    // 오늘 승률 PD가 정확히 나오는 최소한의 게임 수
    int d_min = 100 / gcd(100, PD);

    // 오늘 한 게임 수 D는 N 이하
    if(d_min > N){
        return 1;
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
        long long N;
        int PD, PG;
        cin >> N >> PD >> PG;
        cout << '#' << TC << ' ' << result[solution(N, PD, PG)] << '\n';
    }
    return 0;
}