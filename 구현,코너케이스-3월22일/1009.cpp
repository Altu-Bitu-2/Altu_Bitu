#include<iostream>
#include<vector>

using namespace std;

int main() {
	int T;
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
			cout << 10<<"\n";
		else
			cout << ans<<"\n";
	}

}
