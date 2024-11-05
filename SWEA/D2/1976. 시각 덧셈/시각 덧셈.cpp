#include<iostream>
using namespace std;

void func(){
 	int h, hh, m, mm;
    cin >> h >> m >> hh >> mm;
    hh = hh + h > 12 ? (hh + h) % 12 : hh + h;
    mm += m;
    if(mm >= 60){
     	mm -= 60;
        hh++;
    }
    cout << hh << ' ' << mm;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cout << '#' << i << ' ';
        func();
        cout << '\n';
    }
    return 0;
}
        