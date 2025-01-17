#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();

    // 1. 알파벳 변경 횟수 계산
    for (int i = 0; i < n; ++i) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    }

    // 2. 최소 커서 이동 계산
    int minMove = n - 1; // 오른쪽으로 쭉 이동하는 경우 (최대 이동)
    for (int i = 0; i < n; ++i) {
        int next = i + 1;
        while (next < n && name[next] == 'A') {
            next++; // 연속된 'A'를 건너뜀
        }
        // 현재 위치(i)에서 되돌아가거나, 끝까지 갔다가 돌아오는 최소 거리 계산
        int move = i + n - next + min(i, n - next);
        minMove = min(minMove, move);
    }

    answer += minMove;
    return answer;
}
