#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    long long total = 0;
    unordered_map<string, priority_queue<int>> info;
    for(int n = 0; n < N; n++){
        int op, opNum;
        string name;
        cin >> op >> name >> opNum;
        if(op == 1){
            for(int i = 0; i < opNum; i++){
                int temp;
                cin >> temp;
                info[name].push(temp);
            }
        } else {
            if (info[name].empty()) continue;
            
            for(int i = 0; i < opNum; i++){
                if(info[name].empty()) break;
                
                total += info[name].top();
                info[name].pop();
            }
        }
    }

    cout << total << "\n";
    
    return 0;
}