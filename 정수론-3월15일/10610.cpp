#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string input;
	vector<int> v;
	cin >> input;
	int sum = 0;
	bool check = false;
	for (int i = 0; i < input.size(); i++) {
		int n = input[i] - '0';    //string의 각 자릿수를 숫자로 변환
		v.push_back(n);   //vector에 삽입(내림차순으로 sort하기 위함)
		sum += n;  //각 자릿수의 합
		if (n == 0)    //자릿수 중에 0이 있다면
			check = true;
	}
	if (check && sum % 3 == 0) {    //숫자에 0이 존재하고 각자릿수의 합이 3의 배수여야 30의 배수이다
		sort(v.begin(), v.end(), greater<>());    //내림차순으로 sort
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}
	else {
		cout <<"-1";
	}
}