#include<iostream>
#include<vector>
using namespace std;

#define SIZE 10001
int arr[SIZE] = { 0, };
int brr[SIZE] = { 0, };
int N;

void check() {
	for (int i = 1; i <= N; i++) {
		if (arr[i] != brr[i]) return;
	}
	cout << 1 << "\n";
	exit(0);
}

void insertion_sort() {
	for (int i = 2; i <= N; i++) {
		int loc = i - 1;
		int newItem = arr[i];

		while (1 <= loc && newItem < arr[loc]) {
			arr[loc + 1] = arr[loc];
			loc--;
			check();
		}

		if (loc + 1 != i) {
			arr[loc + 1] = newItem;
			check();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> brr[i];
	}

	check();
	insertion_sort();
	cout << 0 << "\n";
}