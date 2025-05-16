#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
string chars = "";
vector<string> answer;

bool isVslid(const string& password);
void dfs(int idx, string password);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> C;
    chars.reserve(C);
    for(int c = 0; c < C; c++){
        cin >> chars[c];
    }

    sort(chars.begin(), chars.end());
    dfs(0, "");
    sort(answer.begin(), answer.end());

    for(string password : answer){
        cout << password << '\n';
    }
    
    return 0;
}

bool isVslid(const string& password){
    int vowels = 0, consonants = 0;
    for(char c : password){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            vowels++;
        } else {
            consonants++;
        }
    }
    return vowels >= 1 && consonants >= 2;
}

void dfs(int idx, string password){
    if(password.length() == L){
        if(isVslid(password)) {
            sort(password.begin(), password.end());
            answer.push_back(password);
        }
        return;
    }

    for(int i = idx; i < C; i++){
        dfs(i + 1, password + chars[i]);
    }
}