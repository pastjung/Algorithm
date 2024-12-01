#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int func(int N, vector<int> days){
	int minimum = 1000000;
    
    for (int i = 0; i < 7; i++) {
        if (days[i] == 1) {
    		int count = 0, temp = 0;      
            for (int j = i; j < 7; j = (j + 1) % 7) {
            	temp++;
            	if (days[j] == 1) count++;
            	if (count == N) break;
            }
            minimum = min(minimum, temp);
        }
    }
    return minimum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N;
        cin >> N;
        vector<int> days(7, 0);
        for(int n = 0; n < 7; n++) cin >> days[n];
        cout << '#' << i << ' ' << func(N, days) << '\n';
    }
    return 0;
}