#include<iostream>
using namespace std;

#define SIZE 500001
long arr[SIZE] = { 0, };
int N;
long count = 0;

void MenOfPassion() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				::count++;
			}
		}
	}
	cout << ::count << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	MenOfPassion();
	cout << 3 << "\n";	
}