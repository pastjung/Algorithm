#include <vector>
#include <queue>
#include <climits>
using namespace std;

// 다익스트라 : 1번 마을부터 K 시간 이하로 배달이 가능한 마을의 수 반환
int dijkstra(vector<vector<pair<int, int>>>& adjList, int K){
    int n = adjList.size();                                                // 그래프 크기
    vector<int> distance(n, INT_MAX);                                      // 시작 정점에서 각 정점까지의 최단 거리
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // 우선순위 큐
    
    // 초기 세팅
    distance[1] = 0;
    pq.push({0, 1});

    // 우선순위 큐 처리
    while(!pq.empty()){
        // 현재 위치 확인
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        
        // 이미 처리된 정점이면 무시
        if(currentDistance > distance[currentNode]) continue;
        
        // 인접 노드 처리
        for(const auto& edge : adjList[currentNode]){
            int cost = currentDistance + edge.second;
            if(cost < distance[edge.first]){
                distance[edge.first] = cost;
                pq.push({cost, edge.first});
            }
        }
    }

    // 최단 거리가 K 이하인 개수 계산
    int answer = 0;
    for(int dist : distance){
        if(dist <= K){
            answer++;
        }
    }
    
    return answer;
}

int solution(int N, vector<vector<int>> road, int K) {
    // 간선 정보를 활용해서 인접 인덱스 생성
    vector<vector<pair<int, int>>> adjList(N + 1);
    for(vector<int> edge : road){
        adjList[edge[0]].push_back({edge[1], edge[2]});
        adjList[edge[1]].push_back({edge[0], edge[2]});  // 양방향 도로
    }
    
    // 다익스트라 알고리즘 계산한 결과 반환
    return dijkstra(adjList, K);
}