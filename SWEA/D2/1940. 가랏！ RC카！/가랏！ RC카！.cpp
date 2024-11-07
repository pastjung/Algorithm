#include<iostream>
using namespace std;

int func(int N){
    int dis = 0, s = 0, c1, c2;
    for(int i = 1; i <= N; i++){
        cin >> c1;
        if(c1 == 1){
            cin >> c2;
         	s += c2;
        } else if(c1 == 2) {
            cin >> c2;
            if(s - c2 <= 0) s = 0;
            else s -= c2;
        }   
        dis += s;
    }
    return dis;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
		int N;
        cin >> N;
        cout << '#' << i << ' ' << func(N) << '\n';
    }
    return 0;
}