#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string calRank(int rank, int N){
 	if(rank <= N / 10) return "A+";
    else if (rank <= 2 * N / 10) return "A0";
    else if (rank <= 3 * N / 10) return "A-";
    else if (rank <= 4 * N / 10) return "B+";
    else if (rank <= 5 * N / 10) return "B0";
    else if (rank <= 6 * N / 10) return "B-";
    else if (rank <= 7 * N / 10) return "C+";
    else if (rank <= 8 * N / 10) return "C0";
    else if (rank <= 9 * N / 10) return "C-";
    else return "D0";
}

string func(vector<pair<int, int>> scores, int N, int K){
    int rank = 1;
    for(pair<int,int> score : scores){
     	if(score.first == K) return calRank(rank, N);
        else rank++;
    }
}

bool cmp( pair<int, int> s1, pair<int, int> s2){
 	return s1.second > s2.second;   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        vector<pair<int, int>> scores;
        // 데이터 입력
        int N, K;
        cin >> N >> K;
        for(int j = 1; j <= N; j++){
            int midterm_exam, final_exam, assignment;
            cin >> midterm_exam >> final_exam >> assignment;
            midterm_exam *= 35;
            final_exam *= 45;
            assignment *= 20;
            int score = midterm_exam + final_exam + assignment;
            scores.push_back(pair<int, int>(j, score));		// 학생 순서, 비중 총점
        }
        
        // 정렬
        stable_sort(scores.begin(), scores.end(), cmp);
        
        // 정답 출력
        cout << '#' << i << ' ' << func(scores, N, K) << '\n';
    }
    return 0;
}