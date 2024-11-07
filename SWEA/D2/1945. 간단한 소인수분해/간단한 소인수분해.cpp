#include<iostream>
#include<vector>
using namespace std;

void func(int N){
    int arr[5] = { 2, 3, 5, 7, 11 };
	int index[5] = {0, };
    
	for(int i = 0; i < 5; i++){
        while(N != 1){
         	if(N % arr[i] == 0){
                index[i]++;
             	N /= arr[i];   
            } else{
                break;
            }
        }
    }
    
    for(int n : index){
     	cout << n << ' ';   
    }
    cout << '\n';
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
        cout << '#' << i << ' ';
        func(N);
    }
    return 0;
}