#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parents;    // 각 컴퓨터의 상위 컴퓨터를 저장할 배열
vector<int> ranks;      // 각 네트워크의 랭크

// find 함수
int find(int x){
    if(parents[x] != x){
        parents[x] = find(parents[x]);
    }
    return parents[x];
}

// union 함수 -> rank 고려
void unionSet(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    
    if(rootX != rootY){
        if(ranks[rootX] < ranks[rootY]){
            parents[rootX] = rootY;
        } else if(ranks[rootX] > ranks[rootY]){
            parents[rootY] = rootX;
        } else{
            parents[rootY] = rootX;
            ranks[rootX]++;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    parents.assign(n, 0);
    ranks.assign(n, 0);
    
    for(int i = 0; i < n; i++){
        parents[i] = i;
    }
    
    // 상위 컴퓨터 정보 저장 -> 0 ~ n-1까지 저장
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(computers[i][j] == 1){
                unionSet(i, j);
            }
        }
    }
    
    // 대표 노드로 갱신
    for(int i = 0; i < n; i++){
        parents[i] = find(i);
    }
    
    // 각 네트워크의 중복 제거
    sort(parents.begin(), parents.end());
    parents.erase(unique(parents.begin(), parents.end()), parents.end());
    return parents.size();
}