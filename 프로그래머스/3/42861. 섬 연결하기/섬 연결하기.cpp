#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int groupSize = 0;

    vector<bool> group(n, false); // 섬이 연결되었는지 여부
    sort(costs.begin(), costs.end(), cmp); // 비용 기준으로 정렬

    group[costs[0][0]] = true; // 첫 번째 섬 연결
    group[costs[0][1]] = true;
    answer += costs[0][2];
    groupSize = 2;

    while (groupSize < n) {
        for (int i = 0; i < costs.size(); i++) {
            int islandA = costs[i][0];
            int islandB = costs[i][1];
            int cost = costs[i][2];

            // 하나의 섬만 그룹에 포함된 경우
            if (group[islandA] ^ group[islandB]) {
                group[islandA] = true;
                group[islandB] = true;
                answer += cost;
                groupSize++;
                costs.erase(costs.begin() + i);
                break;
            }
        }
    }

    return answer;
}
