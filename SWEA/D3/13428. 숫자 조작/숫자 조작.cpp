#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void func(string str){
 	string minimum = str;
    string maximum = str;
    
    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = i; j < str.length(); j++) {
            if (i != 0 || str[j] != '0'){
             	swap(str[i], str[j]);
                if (str > maximum)
                    maximum = str;
                if (str < minimum)
                    minimum = str;
                swap(str[i], str[j]);
            }
        }
    }
    cout << minimum << ' ' << maximum << '\n';
}

int main(){
 	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
     	string str;
        cin >> str;
        cout << '#' << t << ' ';
        func(str);
    }
    return 0;
}