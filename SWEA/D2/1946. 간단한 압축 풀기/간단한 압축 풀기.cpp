#include<iostream>
#include<string>
using namespace std;

void func(int N){
    char alpha;
    int alpha_count, count = 0;
    string str = "";
    
    for(int i = 1; i <= N; i++){
        cin >> alpha >> alpha_count;
        
        while(0 < alpha_count){           
         	if( 10 <= count + alpha_count ){                
                int remain = 10 - count;
                str += string(remain, alpha);
                cout << str << '\n';
                
                str = "";
                alpha_count -= remain;
                count = 0;
            } else{               
                str += string(alpha_count, alpha);
                count += alpha_count;
                alpha_count = 0;
            }
        }
    }
    cout << str << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    
    for(int i = 1; i <= T; i++){
     	cout << '#' << i << '\n';
        int N;
        cin >> N;
        func(N);
    }
    return 0;
}