#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/* 문제 분석
- 문제 설명
    - 방향 그래프 : 주어진 시작점에서 다른 모든 정점으로의 최단 경로 구하기
    - i번째 줄에 i번 정점으로의 최단 경로의 값 출력 ( 시작점은 자신은 0으로 출력, 경로가 없으면 INF 출력 )
- 입력 데이터
    - 정점의 개수 V
    - 간선의 개수 E
    - 시작 정점 K
    - 간선 + 가중치 : 모든 가중치는 10 이하의 가중치
- 핵심 키워드
    - 양의 가중치 & 최단 경로 -> 다익스트라
*/

void Dijkstra(const vector<vector<pair<int,int>>>& weight, vector<int>& distance, const int K){
    int n = weight.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // {누적 가중치, 도착 정점}

    // 초기 세팅
    distance[K] = 0;
    pq.push({0, K});

    while(!pq.empty()){
        int wSum = pq.top().first;
        int start = pq.top().second;
        pq.pop();

        // 현재 경로가 기존에 찾은 경로보다 가중치가 작은 긴 경우 패스
        if(wSum > distance[start]){
            continue;
        }

        // 인근 경로 탐색
        for(const auto& [end, w] : weight[start]){
            int cost = distance[start] + w;
            if(cost < distance[end]){
                distance[end] = cost;
                pq.push({cost, end});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 데이터
    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int,int>>> weight(V);  // 출발 정점 : {도착 정점, 가중치}
    for(int e = 0; e < E; e++){
        int start, end, w;
        cin >> start >> end >> w;
        weight[start-1].push_back({end-1, w});
    }

    // K부터 각 정점의 최단 경로 계산
    vector<int> distance(V, INT_MAX);  // 각 정점의 최단 경로    
    Dijkstra(weight, distance, K - 1);

    // 모든 최단 경로 출력
    for(int w : distance){
        if(w == INT_MAX){
            cout << "INF\n";
        } else{
            cout << w << "\n";
        }
    }
    
    return 0;
}