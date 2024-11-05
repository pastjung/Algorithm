#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(vector<int> arr){
    stable_sort(arr.begin(), arr.end());
    for(int i = 1; i <= 9; i++){
     	if(arr[i - 1] != i) return false;
    }
    return true;
}

int func(vector<vector<int>> arr){
    // 1* 9 확인
    for(int i = 0; i <9; i++){
     	vector<int> temp;
        temp = arr[i];
        if (!check(temp)) return 0;
    }
    
    // 9 * 1 확인
    for(int i = 0; i < 9; i++){
     	vector<int> temp;
        for(int j = 0; j < 9; j++){
         	temp.push_back(arr[j][i]);
        }
        if (!check(temp)) return 0;
    }    
    
        // 3 * 3 확인
    for(int i = 0; i < 9; i += 3){
        for(int j = 0; j < 9; j += 3){
            vector<int> temp;
            temp.push_back(arr[i][j]);
            temp.push_back(arr[i][j+1]);
            temp.push_back(arr[i][j+2]);
            temp.push_back(arr[i+1][j]);
            temp.push_back(arr[i+1][j+1]);
            temp.push_back(arr[i+1][j+2]);
            temp.push_back(arr[i+2][j]);
            temp.push_back(arr[i+2][j+1]);
            temp.push_back(arr[i+2][j+2]);
            if (!check(temp)) return 0;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        vector<vector<int>> arr(9, vector<int> (9, 0));
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                cin >> arr[j][k];
            }
        }
     	cout << '#' << i << ' ' << func(arr) << '\n';
    }
    return 0;
}