#include<iostream>
#include<string>
using namespace std;

int func(string str){
    string result = "";
    result += str[0];
    for(int i = 1; i < str.size(); i++){
     	string compare = str.substr(i, result.size());
       
        if(result == compare) return result.size();
        else result += str[i];
    }
    
    return result.size();
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
        cout << "#" << i << ' ' << func(str) << "\n";
    }
    
 	return 0;
}