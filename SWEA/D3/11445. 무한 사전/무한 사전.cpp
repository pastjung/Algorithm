#include <iostream>
#include <string>
using namespace std;

char solution(string P, string Q){
    if(P + 'a' != Q){
        return 'Y';
    } else {
        return 'N';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        string P, Q;
        cin >> P >> Q;
        cout << '#' << TC << ' ' << solution(P, Q) << '\n';
    }
    
    return 0;
}