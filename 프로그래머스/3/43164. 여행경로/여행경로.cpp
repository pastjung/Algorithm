#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
풀이 방법
- DFS 사용 -> 모든 도시를 방문하는 경우 탐색
- 동일 경로가 존재할 경우 알파벳 순서 ( 정렬 )
- 항상 ICN에서 출발
*/

bool cmp(const vector<string>& v1, const vector<string>& v2){
    return v1[1] < v2[1];
}

void DFS(const vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& path, string cur){    
    if(path.size() == tickets.size() + 1) return;
    
    for(int i = 0; i < tickets.size(); i++){
        if(!visited[i] && cur == tickets[i][0]){
            visited[i] = true;
            path.push_back(tickets[i][1]);
            
            DFS(tickets, visited, path, tickets[i][1]);
            if(path.size() == tickets.size() + 1) return;
            
            visited[i] = false;
            path.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    // 도착 경로 기준 정렬
    sort(tickets.begin(), tickets.end(), cmp);
    
    vector<bool> visited(tickets.size(), false);
    answer.push_back("ICN");
    
    DFS(tickets, visited, answer, "ICN");
    return answer;
}