#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getParent(vector<int> tree, int node){
    if(node == tree[node]){
        return node;
    } else{
        return tree[node] = getParent(tree, tree[node]);
    }
}

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> tree(101);
    for(int i = 0; i < n; i++){
        tree[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(vector<int> cost : costs){
        int start = getParent(tree, cost[0]);
        int end = getParent(tree, cost[1]);
        int weight = cost[2];
        
        if(start != end){
            tree[end] = start;
            answer += weight;
        }
    }
    
    return answer;
}