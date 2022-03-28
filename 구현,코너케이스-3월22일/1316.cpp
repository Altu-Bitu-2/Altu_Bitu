#include<iostream>
#include<vector>

using namespace std;

bool check(string word) {
	int alphabet[26] = { 0 };
	int s = word.length();
	bool ans = true;
	alphabet[word[0] - 'A'] = 1;
	for (int i = 1; i < s; i++) {
		if (word[i] == word[i - 1]) {
			continue;
		}
		if (alphabet[word[i] - 'A'] == 1) {
			ans = false;
			break;
		}
		alphabet[word[i] - 'A'] = 1;
	}
	return ans;
}

int main() {
	int t;
	int countt = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string n;
		cin >> n;
		if (check(n))
			countt++;
	}
	cout << countt;
	return 0;
}