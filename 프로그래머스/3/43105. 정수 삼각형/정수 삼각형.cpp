#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> tri(triangle);
    int height = triangle.size();
    
    for(int h = 0; h < height - 1; h++){
        for(int i = 0; i < triangle[h].size(); i++){
            tri[h + 1][i] = max(tri[h + 1][i], tri[h][i] + triangle[h + 1][i]);
            tri[h + 1][i + 1] = max(tri[h + 1][i + 1], tri[h][i] + triangle[h + 1][i + 1]);
        }
    }
    
    return *max_element(tri[height - 1].begin(), tri[height - 1].end());
}