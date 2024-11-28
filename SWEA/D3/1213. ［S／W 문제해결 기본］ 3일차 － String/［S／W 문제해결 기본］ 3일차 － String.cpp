#include<iostream>
#include<string>
using namespace std;

int func(string input, string search){
    int count = 0, pos = 0;
    while( ( pos = input.find(search, pos) ) != string::npos){
        count++;
        pos += search.length();		// 다음 검색을 위해 pos를 이동
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T = 10;
    for(int i = 1; i <= T; i++){
        int N;
        string input, search;
        cin >> N >> search >> input;
        cout << '#' << N << ' ' << func(input, search) << '\n';
    }
    return 0;
}