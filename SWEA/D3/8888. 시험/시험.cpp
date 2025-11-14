#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 문제 분석
- 문제 설명
    - N명의 참가자
    - T개의 문제 (부분 문제 X)
    - 각 문제 점수 : 문제를 풀지 못한 참가자의 수
    - 참가자 등수 : (더 높은 점수를 가진 참가자 수) + (동점, 더 많은 문제를 푼 참가자 수) + (동점, 동률, 참가번호가 앞번호인 참가자 수) + 1
    - 지학이 : p번
    - 결론: 지학이의 점수와 등수 계산하기
- 입력 데이터
    - N : 참가자 수(최대 2000)
    - T : 문제 수(최대 2000)
    - P : 지학이 참가 번호
    - 이후 N 줄 : 각 대회 참가자들의 문제 해결 여부(0 : 미해결, 1 : 해결)
    -> N * T = 4,000,000 -> O(NlogN)알고리즘 사용 가능
- 핵심 키워드
    - 각 문제를 해결하지 못한 참가자 수 계산(각 문제의 점수 계산) : O(N)
    - 모든 참가자의 점수 & 해결한 문제 수 계산 : O(N)
    - 정렬 -> 점수, 문제 수, 참가 번호
*/

bool cmp(vector<int> p1, vector<int> p2){
    if(p1[0] == p2[0]){
        if(p1[1] == p2[1]){
            return p1[2] < p2[2];
        }
        return p1[1] > p2[1];
    }
    return p1[0] > p2[0];
}

void solution(int N, int T, int P){
    int result = 0;
    vector<vector<int>> problems(N, vector<int>(T, 0));
    vector<int> unresolved(T, 0);
    vector<vector<int>> scores(N, vector<int>(3, 0));  // {점수, 해결한 문제 수, 참가 번호}

    // 각 문제의 점수 계산
    for(int n = 0; n < N; n++){
        for(int t = 0; t < T; t++){
            cin >> problems[n][t];
            if(problems[n][t] == 0){
                unresolved[t]++;
            }
        }
    }

    // 모든 참가자의 점수 & 해결한 문제 수 계산
    for(int n = 0; n < N; n++){
        scores[n][2] = n + 1;
        for(int t = 0; t < T; t++){
            if(problems[n][t] == 1){
                scores[n][0] += unresolved[t];
                scores[n][1]++;
            }
        }
    }

    // 정렬
    stable_sort(scores.begin(), scores.end(), cmp);

    for(int n = 0; n < N; n++){
        if(scores[n][2] == P){
            result = n;
            break;
        }
    }
    cout << scores[result][0] << ' ' << result + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Tc;
    cin >> Tc;
    for(int TC = 1; TC <= Tc; TC++){
        int N, T, P;
        cin >> N >> T >> P;
        cout << '#' << TC << ' ';
        solution(N, T, P);
    }
    return 0;
}