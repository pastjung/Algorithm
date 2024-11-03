#include<iostream>
#include<string>
using namespace std;

void func(int n){
    string three = "";
    int num = n;
    do {
     	int e = num % 10;
        if( e != 0 && e % 3 == 0 ){
        	three += "-";   
        }
        num /= 10;
    } while ( num != 0 );
    
    if(three != "")	cout << three;  
    else	cout << n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
 		func(i);
        if(i==N) cout << '\n';
        else cout << ' ';
    }
 
    return 0;
}