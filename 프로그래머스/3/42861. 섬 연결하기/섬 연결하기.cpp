#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 특정 노드의 대표(parent)를 찾는 함수 (경로 압축 기법 사용)
int getParent(vector<int>& tree, int node){
    if(node == tree[node]){
        return node;
    } else{
        // 부모를 재귀적으로 찾고 경로 압축
        return tree[node] = getParent(tree, tree[node]);
    }
}

// 간선을 비용 기준으로 오름차순 정렬하기 위한 비교 함수
bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // 각 노드를 자신을 부모로 초기화 (Disjoint Set 초기화)
    vector<int> tree(101);
    for(int i = 0; i < n; i++){
        tree[i] = i;
    }
    
    // 모든 간선을 비용 기준으로 정렬
    sort(costs.begin(), costs.end(), cmp);
    
    // 정렬된 간선들을 순회하며 MST 구성
    for(vector<int> cost : costs){
        // 현재 간선의 두 노드와 비용
        int start = getParent(tree, cost[0]);  // 시작 노드의 루트 부모
        int end = getParent(tree, cost[1]);    // 끝 노드의 루트 부모
        int weight = cost[2];                  // 간선의 가중치(비용)
        
        // 두 노드가 서로 연결되어 있지 않다면 (사이클이 아니라면)
        if(start != end){
            tree[end] = start;      // 두 집합을 합침 (Union)
            answer += weight;       // 간선의 비용을 결과에 더함
        }
    }
    
    return answer;
}