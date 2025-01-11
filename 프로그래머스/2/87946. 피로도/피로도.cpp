#include <string>
#include <vector>

using namespace std;

void dfs(int index, int k, vector<vector<int>> dungeons, vector<bool> visited, int& answer) {
    if (index > answer) {
        answer = index;
    }
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;
            dfs(index + 1, k - dungeons[i][1], dungeons, visited, answer);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);

    dfs(0, k, dungeons, visited, answer);
    
    return answer;
}