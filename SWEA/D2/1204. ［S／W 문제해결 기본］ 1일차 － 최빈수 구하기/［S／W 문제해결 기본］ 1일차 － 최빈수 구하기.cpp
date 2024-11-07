#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(){
    vector<int> scores(101, 0);
    for(int i = 1; i <= 1000; i++){
     	int temp;
        cin >> temp;
        scores[temp]++;
    }
    int max = scores[0], max_index = 0;
    for(int i = 0; i <= 100; i++){
        if(max <= scores[i]) {
            max = scores[i];
            max_index = i;
        }
    }
    return max_index;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--){
     	int t;
        cin >> t;
        cout << '#' << t << ' ' << func() << '\n';
    }
    return 0;
}