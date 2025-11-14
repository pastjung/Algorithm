#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* 문제 분석
- 문제 설명
    - 원래 이진 문자열이 무엇인지 까먹음
    - 원래 문자열을 복원해 내기 위한 정보를 구축
        - 인접한 두 문자를 끊어 봤을 때 각각의 쌍이 몇 번씩 등장하는지 적어 놓음
        - 단, 인접한 두 문자를 끊어 볼 때 한칸씩 이동하여 확인
    - 결론: 원래 문자열로 가능한 문자열이 있는지 확인 -> 가능할 경우 아무거나 출력
- 입력 데이터
    - 00, 01, 10, 11의 개수 A, B, C, D
        - 각각 최대 20개 -> 총 20*20*20*20 = 160,000 -> 모든 경우의 수를 계산하면 시간 초과\
- 핵심 키워드
    - dfs로 계속 이어질 수 있는지 확인 -> dfs가 종료되었는데 반환값이 없으면 impossible
    - 0으로 끝나는 경우 == 0으로 시작하는 경우 && 1로 끝나는 경우 == 1로 시작하는 경우 -> 아닐 경우 impossible
        - 0으로 끝나는 경우 : 00 10
        - 1로 끝나는 경우 : 01 11
        - 0으로 시작하는 경우 : 00 01
        - 1로 시작하는 경우 : 10 11
    - 01패턴과 10패턴은 항상 개수가 같거나, 혹은 개수 차이가 1개
*/

bool dfs(string& answer, string temp, char last, int A, int B, int C, int D){
    // 불가능한 경우 : 01패턴과 10패턴은 항상 개수가 같거나, 혹은 개수 차이가 1개
    if(abs(B - C) > 1){
        return false;
    }

    // 불가능한 경우 : 음수가 되는 경우
    if(A < 0 || B < 0 || C < 0 || D < 0){
        return false;
    }

    if(A == 0 && B == 0 && C == 0 && D == 0){
        answer = temp;
        return true;
    }

    if(last == '0'){
        if(dfs(answer, temp + '0', '0', A - 1, B, C, D)) return true;
        if(dfs(answer, temp + '1', '1', A, B - 1, C, D)) return true;
    } else{
        if(dfs(answer, temp + '0', '0', A, B, C - 1, D)) return true;
        if(dfs(answer, temp + '1', '1', A, B, C, D - 1)) return true;
    }
    return false;
}
        

string solution(int A, int B, int C, int D){
    string answer = "impossible";
    
    if(dfs(answer, "0", '0', A, B, C, D)) return answer;
    if(dfs(answer, "1", '1', A, B, C, D)) return answer;
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        cout << '#' << TC << ' ' << solution(A, B, C, D) << '\n';
    }
    return 0;
}