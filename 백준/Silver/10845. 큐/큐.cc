#include<iostream>
using namespace std;

#define SIZE 10001
int N;

class queue {
private:
	int arr[SIZE] = { 0, };
	int front_index;
	int back_index;
	int length;

public:
	queue() {
		front_index = 0;
		back_index = -1;
		length = 0;
	}
	void push(int X);
	void pop();
	void size();
	void empty();
	void front();
	void back();
};
void queue::push(int X) {
	back_index = (back_index + 1) % SIZE;
	arr[back_index] = X;
	length++;
}

void queue::pop() {
	if (front_index == back_index + 1) cout << -1 << "\n";
	else {
		cout << arr[front_index] << "\n";
		front_index = (front_index + 1) % SIZE;
		length--;
	}
}

void queue::size() {
	cout << length << "\n";
}

void queue::empty() {
	if (front_index == back_index + 1) cout << 1 << "\n";
	else cout << 0 << "\n";
}

void queue::front() {
	if (front_index == back_index + 1) cout << -1 << "\n";
	else cout << arr[front_index] << "\n";
}

void queue::back() {
	if (front_index == back_index + 1) cout << -1 << "\n";
	else cout << arr[back_index] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue q;

	cin >> N;
	while (N--) {
		string command;
		cin >> command;

		if (command == "push") {
			int value;
			cin >> value;
			q.push(value);
		}
		else {
			if (command == "front") q.front();
			else if (command == "back") q.back();
			else if (command == "size") q.size();
			else if (command == "pop") q.pop();
			else if (command == "empty") q.empty();
		}
	}
}