#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string func(vector<int> people, int N, int M, int K){
    stable_sort(people.begin(), people.end());
    
    int inventory = 0, preTime = 0;
    for(int time : people){
     	inventory += ( time / M - preTime / M ) * K;
        if(inventory == 0) return "Impossible";
        else {
            inventory--;  
            preTime = time;
        }
    }
	return "Possible";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
		int N, M, K;
        cin >> N >> M >> K;
        vector<int> people(N, 0);
        for(int j = 0; j < N; j++){
            cin >> people[j];
        }
        cout << '#' << i << ' ' << func(people, N, M, K) << '\n';
    }
    return 0;
}
    
    