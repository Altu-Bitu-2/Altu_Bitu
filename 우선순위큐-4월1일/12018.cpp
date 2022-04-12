#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
 
int main() {
	int n, m;
	int count = 0;

	cin >> n >> m;
	vector<int> maxmil(n, 0);  //넣어야하는 최소 마일리지 배열
	for (int i = 0; i < n; i++) {
		int p, l;
		cin >> p >> l;
		vector<int> v(p, 0);
		for (int i = 0; i < p; i++) {
			cin >> v[i];
		}
		if (p < l) {  //정원보다 신청한 사람이 적을 경우
			maxmil[i] = 1;  //어차피 들을 수 있는 과목이니까 최소 마일리지인 1을 사용
		}
		else {  //정원과 신청한 사람이 같거나 신청한 사람이 많을 경우
			sort(v.begin(), v.end());  //오름차순으로 정렬
			maxmil[i] = v[p-l];  //l번째로 많이 넣은 사람의 마일리지만큼(같으면 성준이한테 우선순위가 주어지니까)
		}
	}
	sort(maxmil.begin(), maxmil.end());  //마일리지를 정렬
	int x = 0;  //마일리지 배열 인덱스로 사용
	while (x<n) {
		m -= maxmil[x];  //최소 마일리지 값부터 빼기
		if (m >= 0) {
			count++;  //들을수있는 과목 수+1
			x++;
			continue;
		}
		else
			break;
	}

	cout << count;
	return 0;
}