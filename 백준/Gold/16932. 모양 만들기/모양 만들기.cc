#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

/* 문제 분석
- 문제 설명
    - N*M 배열에서 1이 연결된 최대 길이 탐색
    - 이때 1개의 모양만 1로 변경 가능
- 입력 데이터
    - N : 행 ( 2 <= N <= 1000 )
    - M : 열 ( 2 <= M <= 1000 )
- 핵심 키워드
    - 1개의 모양만 1로 변경
    - 상하좌우로 연결된 경우만 인정
    - 모든 0에서 BFS로 확인 -> O((NM)^2) = 10^12 > O(1억)
    - BFS로 visited에 그룹 번호 할당 -> 각 그룹의 크기를 별도의 배열에 저장 -> 모든 0체크 -> 상하좌우 그룹 파악해서 최대값 탐색
*/

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solve(int N, int M, vector<vector<int>>& arr) {
    vector<vector<int>> group_id_map(N, vector<int>(M, 0));
    vector<int> group_size;
    group_size.push_back(0); // ID 0은 바다(0)를 의미하므로 빈 값 채움

    int current_id = 1;
    int max_area = 0;

    // 1. BFS로 그룹화 및 그룹 크기 측정
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1 && group_id_map[i][j] == 0) {
                int count = 0;
                queue<pair<int, int>> q;

                q.push({i, j});
                group_id_map[i][j] = current_id;
                
                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    count++;

                    for (int d = 0; d < 4; d++) {
                        int nr = r + dy[d];
                        int nc = c + dx[d];
                        if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                            if (arr[nr][nc] == 1 && group_id_map[nr][nc] == 0) {
                                group_id_map[nr][nc] = current_id;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
                group_size.push_back(count);
                max_area = max(max_area, count); // 이미 1로만 이루어진 최대 그룹이 답일 수도 있음
                current_id++;
            }
        }
    }

    // 2. 0을 하나씩 1로 바꿔보며 인접 그룹 합산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                set<int> neighbors; // 중복 그룹 방지
                for (int d = 0; d < 4; d++) {
                    int nr = i + dy[d];
                    int nc = j + dx[d];
                    if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                        if (group_id_map[nr][nc] > 0) {
                            neighbors.insert(group_id_map[nr][nc]);
                        }
                    }
                }

                int current_total = 1; // 바꾼 0 자신 포함
                for (int id : neighbors) {
                    current_total += group_size[id];
                }
                max_area = max(max_area, current_total);
            }
        }
    }

    return max_area;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M, 0));
    for(int n = 0; n < N; n++){
        for(int m = 0; m < M; m++){
            cin >> arr[n][m];
        }
    }
    cout << solve(N, M, arr) << '\n';
    return 0;
}