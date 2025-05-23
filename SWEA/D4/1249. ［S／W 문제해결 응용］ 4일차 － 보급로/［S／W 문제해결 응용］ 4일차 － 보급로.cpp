#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <tuple>
using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int dijkstra(int N, const vector<vector<int>>& map) {
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    dist[0][0] = 0;
    pq.push(make_tuple(0, 0, 0));  // cost, x, y

    while (!pq.empty()) {
        int cost, x, y;
        tie(cost, x, y) = pq.top(); pq.pop();

        if (x == N - 1 && y == N - 1) return cost;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                int nextCost = cost + map[ny][nx];
                if (nextCost < dist[ny][nx]) {
                    dist[ny][nx] = nextCost;
                    pq.push(make_tuple(nextCost, nx, ny));
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<vector<int>> map(N);
        for (int n = 0; n < N; n++) {
            string temp;
            cin >> temp;
            for (char c : temp) {
                map[n].push_back(c - '0');
            }
        }

        int answer = dijkstra(N, map);
        cout << "#" << t << " " << answer << '\n';
    }

    return 0;
}
