#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int answer = 0;
int N, K;
vector<int> wordMaskList;
vector<int> optionalChars;

int countReadable(int mask){
    int cnt = 0;
    for(int w : wordMaskList){
        if((w & mask) == w) cnt++;
    }
    return cnt;
}

void dfs(int idx, int cnt, int mask){
    if(cnt == K){
        answer = max(answer, countReadable(mask));
        return;
    }

    for(int i = idx; i < optionalChars.size(); i++){
        dfs(i + 1, cnt + 1, mask | (1 << optionalChars[i]));
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    if(K < 5){
        cout << 0 << '\n';
        return 0;
    }

    int baseMask = 0;
    for(char c : "antic"){
        baseMask |= (1 << (c-'a'));
    }
    
    for(int n = 0; n < N; n++){
        string word;
        cin >> word;
        int mask = 0;
        for(int i = 4; i < word.size() - 4; i++){
            mask |= (1 << (word[i] - 'a'));
        }
        wordMaskList.push_back(mask);
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (!(baseMask & (1 << (c - 'a')))) {
            optionalChars.push_back(c - 'a');
        }
    }

    dfs(0, 5, baseMask);
    cout << answer << '\n';   
    return 0;
}