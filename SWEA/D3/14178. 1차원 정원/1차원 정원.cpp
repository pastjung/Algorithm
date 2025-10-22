#include <iostream>
#include <vector>
using namespace std;

int solution(int N, int D){
    int answer = 0;
    int range = 2 * D + 1;

    answer += N / range;
    answer += (N % range > 0) ? 1 : 0;
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        int N, D;
        cin >> N >> D;    

        cout << '#' << TC << ' ' << solution(N, D) << '\n';
    }
    return 0;
}