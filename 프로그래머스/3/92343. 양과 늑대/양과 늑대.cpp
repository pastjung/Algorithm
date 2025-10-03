#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adjList;

// dfs
void dfs(vector<int>& info, vector<int> canGo, int& answer, int sheep, int wolf, int cur){
    if(info[cur] == 0){
        sheep++;
    } else{
        wolf++;
    }
    
    if(wolf >= sheep){
        return;
    }
     
    answer = max(answer, sheep);
    
    // 현재 노드를 제거하고 자식 노드 추가
    vector<int> nextCanGo = canGo;
    nextCanGo.erase(find(nextCanGo.begin(), nextCanGo.end(), cur));
    for (int next : adjList[cur]) {
        nextCanGo.push_back(next);
    }

    for (int next : nextCanGo) {
        dfs(info, nextCanGo, answer, sheep, wolf, next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int n = info.size();
    
    // 연결 정보를 저장할 연결 리스트 생성 및 초기화
    adjList.assign(n, {});
    for(vector<int> edge : edges){
        adjList[edge[0]].push_back(edge[1]);
    }
    
    vector<int> canGo = {0};
    dfs(info, canGo, answer, 0, 0, 0);
    
    return answer;
}