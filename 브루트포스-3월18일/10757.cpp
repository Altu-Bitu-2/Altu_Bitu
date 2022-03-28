#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> pplus(string& a, string& b) { 
	int al = a.length();
	int bl = b.length();
	vector<int>ans;

	//ans에 숫자 a의 각 자릿수를 일의 자리수부터 삽입
	for (int i = al - 1; i >= 0; i--) {
		int s = a[i] - '0';
		ans.push_back(s);
	}
	//ans값에 숫자 b의 자릿수들을 일의 자리수부터 일단 모두 더해줌 
	for (int i = 0; i < bl; i++) {
		ans[i] += b[bl - 1 - i] - '0';
	}
	//ans값들 중 10을 넘는 숫자들은 10으로 나누어 나머지만 저장하고 carry로 다음 인덱스 값에 1을 더해줌
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] > 9) {
			ans[i] = ans[i] % 10;
			//제일 높은 자리수에서는 다음 인덱스가 없으니 10이 넘을경우 ans에 1을 삽입하는 것으로 대체
			if (i == ans.size() - 1) {
				ans.push_back(1);
				break;
			}
			ans[i + 1]++;
		}
	}

	return ans;
}

int main() {
	//입력범위가 너무 크니까 일단 문자열로 입력받기
	string a, b;
	cin >> a >> b;
	
	if (a.length() < b.length()) {  //길이가 긴 숫자가 a, 짧은 숫자가 b로 가도록 함
		swap(a, b);
	}

	//출력
	vector<int> ans = pplus(a, b);
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
}
