#include<iostream>
using namespace std;

#define SIZE 500001
long arr[SIZE] = { 0, };
long long N;

void MenOfPassion() {
	cout << ((N - 2) * (N - 1) * N) / 6 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	MenOfPassion();
	cout << 3 << "\n";	
}