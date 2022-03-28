#include<iostream>
#include<vector>

using namespace std;

int main() {
	int T;
	vector<int> v;
	cin >> T;
	int a, b;
	int ans;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		ans = a%10;
		for (int i = 1; i < b; i++) {
			ans *= a;
			ans %= 10;
		}
		if (ans == 0)
			v.push_back(10);
		else
			v.push_back(ans);
	}
	for (int i = 0; i < T; i++) {
		cout << v[i]<<"\n";
	}
}