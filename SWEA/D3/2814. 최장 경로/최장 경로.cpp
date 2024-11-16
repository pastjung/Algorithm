#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<vector<int>> edge(11);
bool visited[11] = {false, };
int max_len = 0;

void DFS(int index, int len){
 	// 결과 갱신
    if(max_len < len) max_len = len;
    
    // 현재 정점에서 갈 수 있는 모든 정점 이동
    for(int node : edge[index]){
     	if(!visited[node]){
         	visited[node] = true;
            DFS(node, len + 1);
            visited[node] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        // 초기화
        int N, M;
        vector<vector<int>> temp_edge(11);
        edge = temp_edge;
        memset(visited, false, sizeof(visited));	// visited 배열을 모두 false로 초기화
        max_len = 0;
        
        // 입력
        cin >> N >> M;
        for(int j = 0; j < M; j++){
         	int x, y;
            cin >> x >> y;
            
            // 간선 정보 등록
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        
        // 각 요소별 DFS 를 사용해 최장 길이 찾기
        for(int j = 1; j <= N; j++){
         	visited[j] = true;
            DFS(j, 1);
            visited[j] = false;
        }
        
        cout << '#' << i << ' ' << max_len << '\n';
    }
    return 0;
}