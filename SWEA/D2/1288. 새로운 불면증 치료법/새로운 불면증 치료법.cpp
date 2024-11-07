#include<iostream>
using namespace std;

int func(int N){
 	int count = 0, check_count = 0;
    bool check[10] = {false, };
	
	while(check_count != 10){
        count++;
        int temp = count * N;
        while(temp != 0){
         	if(check[temp % 10] == false){
             	check[temp % 10] = true;
                check_count++;
            }
            temp /= 10;
        }
    }
    return count * N;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N;
        cin >> N;
        cout << '#' << i << ' ' << func(N) << '\n';
    }
    return 0;
}