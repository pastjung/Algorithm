#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
vector<int> brr;
vector<int> tmp;
int N, cnt = 0;

void check() {
	if (cnt == N) {
		cout << 1 << "\n";
		exit(0);
	}
}

void swap(int i, int t) {
	if (arr[i] == brr[i] && tmp[t] != brr[i]) {
		cnt--;
	}
	if (arr[i] != brr[i] && tmp[t] == brr[i]) {
		cnt++;
	}

	arr[i] = tmp[t];
	check();
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
		swap(i, t);
		i++;
		t++;
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

	cin >> N;

	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		arr.push_back(A);
		tmp.push_back(0);
	}

	for (int i = 0; i < N; i++) {
		int B;
		cin >> B;
		brr.push_back(B);

		if (arr[i] == brr[i]) {
			cnt++;
		}
	}

	check();

	merge_sort(0, N - 1);
	
	check();
	cout << 0 << "\n";

	return 0;
}