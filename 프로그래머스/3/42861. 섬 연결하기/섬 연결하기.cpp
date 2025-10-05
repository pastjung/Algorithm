#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 문제 분석
- 문제 설명
    - 최소의 비용으로 모든 섬이 서로 통행 가능하도록 만들 때 필요한 최소 비용 구하기
    - 양방향 통행 가능
- 입력 데이터
    - 섬의 개수 n
    - 섬 사이 통행 비용 costs
- 핵심 키워드
    - 양의 가중치 & 시작 지점 불분명 -> 크루스칼
*/

bool cmp(vector<int> e1, vector<int> e2){
    return e1[2] < e2[2];
}

vector<int> parents;

int find(int x){
    if(parents[x] != x){
        parents[x] = find(parents[x]);
    }
    return parents[x];
}

bool unionSet(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if(rootX != rootY){
        parents[rootY] = rootX;
        return true;
    }
    return false;
}

// kruscal 알고리즘
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    parents.assign(n, 0);
    for(int i = 0; i < n; i++){
        parents[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(vector<int> cost : costs){
        if(unionSet(cost[0], cost[1])){
            answer += cost[2];
        }
    }
    return answer;
}