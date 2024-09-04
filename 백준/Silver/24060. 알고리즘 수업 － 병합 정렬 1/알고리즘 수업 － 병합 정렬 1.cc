#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
vector<int> tmp;
int N, K, cnt = 0;

void check(int i) {
	cnt++;
	if (cnt == K) {
		cout << arr[i] << "\n";
		exit(0);
	}
}

void merge(int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 0;

	while (i <= q && j <= r) {
		if (arr[i] <= arr[j]) {
			tmp[t++] = arr[i++];
		}
		else {
			tmp[t++] = arr[j++];
		}
	}

	while (i <= q) {
		tmp[t++] = arr[i++];
	}
	while (j <= r) {
		tmp[t++] = arr[j++];
	}

	i = p;
	t = 0;
	while (i <= r) {
		arr[i++] = tmp[t++];
		check(i - 1);
	}
}

void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		arr.push_back(A);
		tmp.push_back(0);
	}

	merge_sort(0, N - 1);

	if (cnt < K) {
		cout << -1 << "\n";
	}

	return 0;
}