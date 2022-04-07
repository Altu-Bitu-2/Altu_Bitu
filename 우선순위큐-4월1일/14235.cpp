#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n,x,y;
	cin >> n;
	priority_queue<int> max_heap;
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (max_heap.empty()) {
				cout << "-1\n";
			}
			else {
				cout << max_heap.top() << "\n";
				max_heap.pop();
			}
		}
		else {
			for (int i = 0; i < x; i++) {
				cin >> y;
				max_heap.push(y);
			}
		}
		
	}
	
	return 0;
}

