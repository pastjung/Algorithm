#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int func(string str){
    string halfStr = str.substr(0, str.size()/2);
    string reStr;
    
    if( str.size() % 2 == 0 ){
        reStr = str.substr(str.size()/2, str.size());
    }else{
        reStr = str.substr(str.size()/2 + 1, str.size());
    }
    reverse(reStr.begin(), reStr.end());
    if(halfStr == reStr) return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        string str;
        cin >> str;
        cout << '#' << i << ' ' << func(str) << '\n';
    }
    return 0;
}