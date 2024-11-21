#include<iostream>
#include<queue>
using namespace std;

void func(queue<int> arr){
    int n = 1;
    bool check = true;
    while(check){
        for(int i = 1; i <= 5; i++){
        	int first = arr.front();    
            if(first - i <= 0) {
                arr.push(0);
                arr.pop();
                check = false;
                break;
            } else{
                arr.push(first - i);
                arr.pop();
            }
        }  
    }
    
    while(!arr.empty()){
     	cout << arr.front() << ' ';
        arr.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T = 10;
    for(int i = 1; i <= T; i++){
     	int N;
        cin >> N;
        
        queue<int> arr;
        for(int j = 0; j < 8; j++) {
            int tmp;
            cin >> tmp;
            arr.push(tmp);
        }
        
        cout << '#' << i << ' ';
        func(arr);
        cout << '\n';
    }
    return 0;
}