#include<iostream>
using namespace std;

#define SIZE 10001
int N;

class stack {
private:
	int arr[SIZE] = { 0, };
	int top_index;

public:
	stack() {
		top_index = -1;
	}
	void push(int X);
	void pop();
	void size();
	void empty();
	void top();
};
void stack::push(int X) {
	arr[++top_index] = X;
}

void stack::pop() {
	if (top_index == -1) cout << -1 << "\n";
	else {
		cout << arr[top_index] << "\n";
		arr[top_index--] = 0;
	}
}

void stack::size() {
	cout << top_index + 1 << "\n";
}

void stack::empty() {
	if (top_index == -1) cout << 1 << "\n";
	else cout << 0 << "\n";
}

void stack::top() {
	if (top_index == -1) cout << -1 << "\n";
	else cout << arr[top_index] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack s;

	cin >> N;
	while (N--) {
		string command;
		cin >> command;

		if (command == "push") {
			int value;
			cin >> value;
			s.push(value);
		}
		else {
			if (command == "top") s.top();
			else if (command == "size") s.size();
			else if (command == "pop") s.pop();
			else if (command == "empty") s.empty();
		}
	}
}