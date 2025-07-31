#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 상호배타적 집합 정의
class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int size) : parent(size, -1), rank(size, 0) {}
    int find(int node);                     // 경로 압축을 하면서 루트 노드 찾기
    void merge(int node1, int node2);       // 랭크 기반으로 두 집합 합치기
    bool isCycle(int node1, int node2);     // 간츤 집합에 있는지 확인
};

int DisjointSet::find(int node){
    if(parent[node] == -1){
        return node;
    }
    return parent[node] = find(parent[node]);
}

void DisjointSet::merge(int node1, int node2){
    int root1 = find(node1);
    int root2 = find(node2);
    
    if(root1 != root2){
        if(rank[root1] > rank[root2]){
            parent[root2] = root1;
        } else if(rank[root1] < rank[root2]){
            parent[root1] = root2;
        } else{
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}

bool DisjointSet::isCycle(int node1, int node2){
    return find(node1) == find(node2);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // 비용을 기준으로 간선 정렬
    sort(costs.begin(), costs.end(),
        [](const vector<int>& a, const vector<int>& b){ return a[2] < b[2]; });
    
    DisjointSet disjointSet(n);
    
    for(const auto& edge : costs){
        int node1 = edge[0];
        int node2 = edge[1];
        int cost = edge[2];
        
        // 사이클을 확인 후 없으면 합병
        if(!disjointSet.isCycle(node1, node2)){
            disjointSet.merge(node1, node2);
            answer += cost;
        }
    }

    
    return answer;
}