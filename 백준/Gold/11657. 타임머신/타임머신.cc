#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

/* 문제 분석
- 문제 설명
    - N개의 도시 -> 정점 개수
    - 한 도시에서 출발하여 다른 도시로 도착하는 버스가 M개 -> 간선 개수
    - 각 버스는 A 시작 도시, B 도착 도시, C 이동 시간로 나뉨 -> 간선 정보
    - C는 음수 가능 -> 벨만-포드
        - C = 0인 경우는 순간 이동을 하는 경우
        - C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우
    - 1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램 작성
    - 사이클이 생길 경우 -1 출력
    - 사이클이 없을 경우 각 도시의 가장 빠른 시간 출력 ( 만약 해당 도시로 가는 경로가 없을 경우 -1 출력 )
- 입력 데이터
    - 도시 개수 N : 정점 개수
    - 버스 노선의 개수 M : 간선 개수
    - 버스 노선 정보 A, B, C : 간선 정보
*/

const int START = 0;

bool Bellman_Ford(const vector<tuple<int, int, int>>& bus, vector<long long>& distance){
    int N = distance.size();

    // 초기 세팅
    distance[START] = 0;

    // E-1번 누적 가중치 갱신
    for(int n = 1; n < N; n++){
        for(auto&[start, end, weight] : bus){
            if(distance[start] != INT_MAX && distance[end] > distance[start] + weight){
                distance[end] = distance[start] + weight;
            }    
        }
    }

    // 사이클 여부 판단
    for(auto[start, end, weight] : bus){
        if(distance[start] != INT_MAX && distance[end] > distance[start] + weight){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 데이터
    int N, M;
    cin >> N >> M;
    
    vector<tuple<int, int, int>> bus;
    for(int m = 0; m < M; m++){
        int A, B, C;
        cin >> A >> B >> C;
        bus.push_back({A - 1, B - 1, C});
    }

    // 1번 도시부터 최단 거리 계산 -> 사이클이 존재하는 경우 -1 출력
    vector<long long> distance(N, INT_MAX);
    if(!Bellman_Ford(bus, distance)){
        cout << -1 << '\n';
    } else{
        for(int n = 1; n < N; n++){
            if(distance[n] == INT_MAX){
                cout << -1 << '\n';
            } else{
                cout << distance[n] << '\n';
            }
        }
    }
    
    return 0;
}