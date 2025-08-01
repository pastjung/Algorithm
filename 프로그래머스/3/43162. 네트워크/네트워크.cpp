#include <vector>
#include <unordered_set>
using namespace std;

// find 함수 ( 경로 압축 )
int find(vector<int>& parent, int x){
    if(parent[x] != x){
        parent[x] = find(parent, parent[x]);  // 경로 압축
    }
    return parent[x];
}

// unionSet 함수
void unionSet(vector<int>& parent, int a, int b){
    int rootA = find(parent, a);
    int rootB = find(parent, b);
    if(rootA != rootB){
        parent[rootB] = rootA;
    }
}

int solution(int n, vector<vector<int>> computers) {
    // 부모 배열 생성 및 초기화
    vector<int> parent(n);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    
    // 모든 노드 Union
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && computers[i][j] == 1){
                unionSet(parent, i, j);
            }
        }
    }
    
    // 네트워크 개수 계산
    unordered_set<int> networks;
    for(int i = 0; i < n; i++){
        networks.insert(find(parent, i));
    }
    
    return networks.size();
}