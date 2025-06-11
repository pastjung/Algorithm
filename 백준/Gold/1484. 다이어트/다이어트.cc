#include <iostream>
#include <set>
#include <cmath>
using namespace std;

/*
소인수분해 -> 루트(G) 부터 G까지 확인
a^2 - b^2 = (a-b)(a+b) -> a - b + a + b = 2a = G
1 * 15 -> 2a = 16 -> a = 8
3 * 5 -> 2a = 8 -> a = 4
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int G;
    cin >> G;

    set<int> weight;
    for(int x = sqrt(G) + 1; x <= G; x++){
        if(G % x != 0){
            continue;
        }
        
        int y = G / x;
        int a = (x + y) / 2;
        int b = (x - y) / 2;

        if ((x + y) % 2 == 0 && b >= 1){
            weight.insert(a);
        }
    }

    if(weight.empty()){
        cout << -1 << '\n';
    } else{
        for(int w : weight){
            cout << w << '\n';
        }
    }
    
    return 0;
}