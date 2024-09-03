// 교환

#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
vector<int> brr;
int N, cnt = 0;

void isSame() {
	if (cnt == N) {
		cout << 1 << "\n";
		exit(0);
	}
}

void swap(int i, int j) {
	cnt -= ((arr[i] == brr[i]) + (arr[j] == brr[j]));

	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;

	cnt += ((arr[i] == brr[i]) + (arr[j] == brr[j]));

	isSame();
}

int partition(int p, int r) {
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (arr[j] <= x) swap(++i, j);
	}

	if (i + 1 != r) swap(r, i + 1);

	return i + 1;
}

void quick_sort(int p, int r) {
	if (p < r) {
		int q = partition(p, r);	

		quick_sort(p, q - 1);
		quick_sort(q + 1, r);
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
	}

	for (int i = 0; i < N; i++) {
		int B;
		cin >> B;
		brr.push_back(B);

		if (arr[i] == brr[i]) cnt++;
	}

	isSame();

	quick_sort(0, N - 1);

	cout << 0 << "\n";

	return 0;
}