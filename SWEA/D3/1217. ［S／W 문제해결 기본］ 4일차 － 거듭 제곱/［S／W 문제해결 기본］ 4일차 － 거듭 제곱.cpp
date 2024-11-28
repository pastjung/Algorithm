#include<iostream>
using namespace std;

int func(int A, int B){
    if(B == 0) return 1;
    else return A * func(A, B - 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 1; i <= 10; i++){
     	int T, A, B;
        cin >> T >> A >> B;
        cout << '#' << T << ' ' << func(A, B) << '\n';
    }
    return 0;
}