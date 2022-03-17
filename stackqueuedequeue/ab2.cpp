#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//문제1213
//개수가 홀수개인 알파벳이 두개이상이면 팰린드롬을 만들 수 없다

int main() {
	string s;
	int alpha[26] = { 0 };     //알파벳배열
	cin >> s; //입력
	for (int i = 0; i < s.length(); i++) {
		alpha[s[i] - 'A']++;            //알파벳 -'A'를 하면 A=0, .....Z=25가 된다
	}
	string ans = "";
	string tmp = "";       //뒤집은 문자열 저장할 스트링
	int count=0;
	int mid;       //가운데 인덱스(홀수개인 알파벳 하나 끼워놓기 위함)
	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 != 0) {    ///알파벳이 홀수개라는 뜻
			count++;     //개수가 홀수인 알파벳 개수
			mid = i;
		}
	}
	if (count > 1) {      //개수가 홀수개인 알파벳이 2개이상일 경우
		cout << "I'm Sorry Hansoo";
	}
	else {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < alpha[i] / 2; j++) {
				ans += i + 'A';        //숫자+'A'를 하면 다시 알파벳이 된다
			}
		}
		tmp += ans;
		reverse(tmp.begin(), tmp.end());    //앞에 문자열을 뒤집어준다
		if (s.length() % 2 != 0) {
			ans += mid + 'A';
			ans += tmp;
			cout << ans;
		}
		else {
			ans += tmp;
			cout << ans;
		}
	}
}
