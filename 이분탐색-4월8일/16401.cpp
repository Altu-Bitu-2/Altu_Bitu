#include <iostream>  //입출력 사용
#include <vector>  //vector 사용
#include <algorithm>  //sort 사용

using namespace std;  //std namespace 사용중

int childNum(int len, vector<int>& snacks) { //몇명에게 나누어줄 수 있는지 출력해주는 함수
    int cnt = 0;  //0으로 초기화
    for (int i = snacks.size() - 1; i >= 0; i--) { //가장 긴 과자부터 검사
        if (snacks[i] < len) { //나누어주려는 길이보다 작아지면 더 이상 못 나눠줌
            break;  //for문 탈출
        }
        cnt += (snacks[i] / len);  //몫을 cnt에 더해줌 그 길이를 몇명에게 나누어 줄 수 있는거니까
    }

    return cnt;  //cnt를 return
}

int upperSearch(int left, int right, int target, vector<int>& snacks) {  //나눠줄 수 있는 과자 최대 길이 출력해주는 함수
    while (left <= right) {  //left는 항상 right이하여야 한다
        int mid = (left + right) / 2; //과자의 길이
        int cnt = childNum(mid, snacks); //과자 길이가 mid일 때 몇 명에게 나눠주는지

        if (cnt >= target) { //target보다 더 많은 아이들에게 나눠준다면 -> 과자 길이를 더 늘릴 수 있음
            left = mid + 1;  //left를 mid 오른쪽으로
        }
        else {  //targer보다 적은 아이들에게 나눠준다면
            right = mid - 1;  //right를 mid 왼쪽으로
        }
    }
    return left - 1;  //오른쪽으로 넘어간 후니까 1빼줌
}

/**
 * [과자 나눠주기]
 *
 * n개의 과자가 있을 때 m명의 조카에게 각각 같은 길이로 줄 수 있는 과자의 최대 길이를 구하는 문제
 * -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?
 *
 * left: 과자 길이의 최솟값 -> 1
 * right: 과자 길이의 최댓값
 *
 * 과자를 몇 명에게 나누어줄 수 있는지 차례로 검사하다 나누어줄 수 없으면 빠져나오기 위해 정렬을 먼저 해주면 좋음
 */

int main() {  //main함수
    int m, n, left = 1, right = 0;  //정수형 변수 선언

    //입력
    cin >> m >> n;  //조카, 과자 수 입력받기
    vector<int> snacks(n, 0);  //vector 0으로 초기화
    for (int i = 0; i < n; i++) {  //과자 수 만큼 반복
        cin >> snacks[i];  //과자 길이 입력받기
    }

    //연산
    sort(snacks.begin(), snacks.end());  //오름차순으로 정렬
    right = snacks[n - 1];  //right는 과자 길이 최댓값

    //연산 & 출력
    cout << upperSearch(left, right, m, snacks);  //나눠줄 수 있는 최대 길이 출력
    return 0;  //0을 return
}