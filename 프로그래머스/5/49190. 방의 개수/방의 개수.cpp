#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> dx = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<int> dy = { 1, 1, 0, -1, -1, -1, 0, 1 };

int solution(vector<int> arrows) {
    int answer = 0;
    set<pair<int, int>> visited_nodes;
    set<pair<pair<int, int>, pair<int, int>>> visited_edges;
    
    int x = 0, y = 0;
    visited_nodes.insert({x, y});
    for(int dir : arrows) {
        for(int step = 1; step <= 2; step++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            pair<int, int> from = {x, y};
            pair<int, int> to = {nx, ny};
            
            // 새로운 간선일 경우
            if(visited_edges.find({from, to}) == visited_edges.end()){
                // 이미 방문한 노드인 경우
                if(visited_nodes.find(to) != visited_nodes.end()){
                    answer++;
                }
            }
            
            visited_edges.insert({from, to});
            visited_edges.insert({to, from});
            visited_nodes.insert(to);
            
            x = nx;
            y = ny;
        }
    }
    
    return answer;
}