#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T = 10;
    for(int i = 1; i <= T; i++){
 		int N, command;
        cin >> N;
        vector<int> code(N, 0);
        for(int n = 0; n < N; n++) cin >> code[n];
        cin >> command;
        for(int c = 0; c < command; c++){
         	char com;
            int X, Y, S;
            cin >> com >> X >> Y;
            for(int y = 0; y < Y; y++){
                cin >> S;
                code.insert(code.begin() + X + y, S);
            }
        }
        cout << '#' << i << ' ';
        for(int j = 0; j < 10; j++) cout << code[j] << ' ';
        cout << '\n';
    }
    return 0;
}