#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//문제11866

int main() {
	int N,K;
	cin >>N>>K;  //입력
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		que.push(i);     //1부터 N까지 삽입
	}
	cout << '<';
	while (que.size() != 0) {    //que사이즈가 0이 되기 전까지 계속
		for (int i = 1; i < K; i++) {      //K번씩 건너뛰는 느낌
			que.push(que.front());      //i번째 사람을 맨 뒤로 보내
			que.pop();
		}
		cout << que.front();
		if (que.size() != 1)   //que에 사람이 한명만 남기 전까지
			cout << ", ";         //띄어쓰기 안해서 백준 틀렸다고 떴었네요..ㅋㅋ
		que.pop();
	}
	cout << '>';

}