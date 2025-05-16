#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int answer = INT_MAX;

int getDistance(pair<int, int> a, pair<int, int> b);
int calcDistance(const vector<int>& selected);
void dfs(int idx, vector<int>& selected);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int temp;
            cin >> temp;
            if(temp == 1){
                home.push_back({i, j});
            } else if(temp == 2){
                chicken.push_back({i, j});
            }
        }
    }

    vector<int> selected;
    dfs(0, selected);
    cout << answer << '\n';
    return 0;
}

int getDistance(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

/*
도시의 치킨 거리 계산
-> 각 집마다 가장 가까운 치킨집을 찾아 거리 계산
-> 모든 집의 최소 치킨 거리의 합을 반환
*/
int calcDistance(const vector<int>& selected){
    int sum = 0;
    for(pair<int, int> h : home){
        int minDist = INT_MAX;
        for(int idx : selected){
            minDist = min(minDist, getDistance(h, chicken[idx]));
        }
        sum += minDist;
    }
    return sum;
}

void dfs(int idx, vector<int>& selected){
    if(selected.size() == M){
        answer = min(answer, calcDistance(selected));
        return;
    }

    for(int i = idx; i < chicken.size(); i++){
        selected.push_back(i);
        dfs(i + 1, selected);
        selected.pop_back();
    }
}