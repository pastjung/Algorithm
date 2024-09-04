#include<iostream>
#include<vector>
using namespace std;

#define SIZE 500001
int arr[SIZE] = { 0, };
int N, K, cnt = 0;

void check(int i, int j) {
	if (K == cnt) {
		if (arr[i] < arr[j]) {
			cout << arr[i] << ' ' << arr[j] << "\n";
		}
		else {
			cout << arr[j] << ' ' << arr[i] << "\n";
		}
		exit(0);
	}
}

void swap(int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

	cnt++;
	check(i, j);
}

void heapify(int k, int n) {
	int left = 2 * k;
	int right = 2 * k + 1;
	int smaller;

	if (right <= n) {
		if (arr[left] < arr[right]) {
			smaller = left;
		}
		else {
			smaller = right;
		}
	}
	else if (left <= n) smaller = left;
	else return;

	if (arr[smaller] < arr[k]) {
		swap(k, smaller);
		heapify(smaller, n);
	}
}

void build_min_heap(int n) {
	for (int i = n / 2; i >= 1; i--) {
		heapify(i, n);
	}
}

void heap_sort() {
	build_min_heap(N);
	for (int i = N; i >= 2; i--) {
		swap(1, i);
		heapify(1, i - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	heap_sort();

	if (cnt < K) {
		cout << -1 << "\n";
	}

	return 0;
}