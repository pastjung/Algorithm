#include<iostream>
#include<vector>
using namespace std;

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int func(int m, int d, int mm, int dd){
    int count = 0;
    for(int i = m; i < mm; i++){
        count += days[i];
    }
    return count + dd - d + 1; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
     	int m, d, mm, dd;
        cin >> m >> d >> mm >>dd;
        cout << '#' << i << ' ' << func(m, d, mm, dd) << '\n';
    }    
    return 0;    
}