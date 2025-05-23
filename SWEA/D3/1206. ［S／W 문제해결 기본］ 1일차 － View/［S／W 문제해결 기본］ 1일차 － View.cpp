#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int build(vector<int>& building){
    int cnt = 0;
    if (building.size() < 5) return 0;
    
    for(int i = 2; i < building.size() - 2; i++){
        int max_neighbor = max({building[i-2], building[i-1], building[i+1], building[i+2]});
        if(building[i] > max_neighbor){
            cnt += building[i] - max_neighbor;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int t = 1; t <= 10; t++){
        int N;
        cin >> N;
        vector<int> building(N, 0);
        for(int n = 0; n < N; n++){
            cin >> building[n];
        }
        
        cout << '#' << t << ' ' << build(building) << '\n';
    }
    
    return 0;
}