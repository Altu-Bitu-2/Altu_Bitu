#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, k, s;
	cin >> n >> k;
	vector<char> v(n, '?');
	int cnt = 0;
	char c;
	for (int i = 0; i < k; i++) {
		cin >> s >> c;
		cnt += s;
		if (v[cnt % n] == '?')
			v[cnt % n] = c;
		else if (v[cnt % n] == c)
			continue;
		else {
			cout << '!';
			return 0;
		}
	}
	bool alphabet[26] = { false };
	for (int i = 0; i < n; i++) {
		alphabet[v[i] - 'A']=true;
	}
	for (int i = 0; i < 26; i++) {
		if (!alphabet) {
			cout << '!';
			return 0;
		}
	}
	for (int i = cnt % n + n; i >= cnt % n + 1; i--) {
		cout << v[i % n];
	}

	return 0;
}

