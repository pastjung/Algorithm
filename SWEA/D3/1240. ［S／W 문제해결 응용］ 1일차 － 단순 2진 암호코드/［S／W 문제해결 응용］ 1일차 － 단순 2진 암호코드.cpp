#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

map<string, int> password = {
	{"0001101", 0},
    {"0011001", 1},
    {"0010011", 2},
    {"0111101", 3},
    {"0100011", 4},
    {"0110001", 5},
    {"0101111", 6},
    {"0111011", 7},
    {"0110111", 8},
    {"0001011", 9}   
};

int func(vector<string> code, int N){
    vector<int> passwordCode;
    int checkResult = 0;
    int result = 0;
 	for(string str : code){
        int index = str.rfind('1');
        if(index != string::npos){
         	for(int i = index - 55; i <= index; i += 7){
                string temp = str.substr(i, 7);
                passwordCode.push_back(password[temp]);
                result += password[temp];
            }
            break;
        }
    }
    
    for(int i = 0; i < 8; i ++){
     	if( (i + 1) % 2 == 1 ) checkResult += 3 * passwordCode[i];
        else if( (i + 1) % 2 == 0 ) checkResult += passwordCode[i];
    }
    
    if(checkResult % 10 ==0 ) return result;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N, M;
        cin >> N >> M;
        vector<string> code(N, "");
        for(int n = 0; n < N; n++){
            cin >> code[n];
        }
        cout << '#' << i << ' ' << func(code, N) << '\n';
    }
    return 0;
}