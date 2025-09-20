#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// banned_id와 user_id를 비교하는 함수
bool check(string user, string ban){
    if(user.size() != ban.size()) return false;
    for(int i = 0; i < user.size(); i++){
        if(ban[i] != '*' && user[i] != ban[i]){
            return false;
        }
    }
    return true;
}

void dfs(vector<vector<int>>& ban, unordered_set<int>& picked, int ban_idx, int bit){
    if(ban_idx == ban.size()){
        picked.insert(bit);
        return;
    }
    
    for(int idx : ban[ban_idx]){
        if(!(bit & (1 << idx))){
            dfs(ban, picked, ban_idx + 1, bit | (1 << idx));
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<int>> ban(banned_id.size());
    
    // 각 banned_id를 비교하기
    for (int i = 0; i < banned_id.size(); i++) {
        for (int j = 0; j < user_id.size(); j++) {
            if (check(user_id[j], banned_id[i])) {
                ban[i].push_back(j);
            }
        }
    }
    
    unordered_set<int> picked;
    dfs(ban, picked, 0, 0);
    return picked.size();
}