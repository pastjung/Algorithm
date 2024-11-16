#include<iostream>
#include<string>
using namespace std;

int func(string mem){
 	int count = 0;
    if(mem[0] == '1') count++;
    for(int i = 0; i < mem.size() - 1; i++){
     	if(mem[i] != mem[i+1]) count++;   
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
     	string mem;
        cin >> mem;
        cout << '#' << i << ' ' << func(mem) << '\n';
    }
    return 0;
}