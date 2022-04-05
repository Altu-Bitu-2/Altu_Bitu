#include <iostream>  //입출력 사용
#include <algorithm>  //sort()사용
#include <vector>  //vector 사용

using namespace std;  //std namespace 사용중

const int SIZE = 8; //배열 크기

int n, m;  //정수형 변수 선언
vector<int> num(SIZE);  //크기가 8인 int형 vector 선언
vector<int> ans(SIZE); //크기가 8인 int형 vector 선언
vector<bool> check(SIZE); //크기가 8인 boolean형 vector 선언

void backtracking(int cnt) {
    if (cnt == m) { //길이 m 이라면 (기저조건)
        for (int i = 0; i < m; i++) {  //길이가 m이니까 m번반복
            cout << ans[i] << ' ';  //수열 출력
        }
        cout << '\n';  //줄바꿈
        return;  //종료
    }
    int prev = 0; //이전에 선택한 값
    for (int i = 0; i < n; i++) {   //n번 반복
        if (!check[i] && prev != num[i]) { //수 위치 중복 체크 && 이전에 탐색한 값이 아니라면
            prev = num[i];  //이전에 선택한 값이라고 넣기
            ans[cnt] = num[i];  //ans수열에 값 넣어주기
            check[i] = true; //선택했으므로 true
            backtracking(cnt + 1);  //재귀함수
            check[i] = false;  //false로 바꿔주는거 잊지말기
        }
    }
}

/**
 * 1. 우선 수열을 사전 순으로 증가하는 순서로 출력해야 하므로 주어진 수열을 오름차순 정렬
 * 2. 이 상태에서 우선, 같은 위치의 수를 또 선택하지 않도록 중복제거 (check 배열 사용)를 해줌
 * 3. 그 후, 중복되는 "수열"을 거르는 방법은 이전에 선택한 값을 변수에 저장해서, 수열을 만들다 다시 루트 노드로 돌아왔을 때
 *    이전에 선택한 값과 같은 값이면 넘어가면 됨! -> 어차피 같은 수이므로 같은 과정 반복해서 똑같은 수열이 나올 것
 */

int main() {   //main 함수
    //입력
    cin >> n >> m;  //n과m입력받기
    for (int i = 0; i < n; i++) {  //n번 반복
        cin >> num[i];  //num배열에 입력받기
    }

    //연산
    sort(num.begin(), num.begin() + n);  //오름차순으로 배열 정리

    //백트래킹 & 출력
    backtracking(0);  //함수 실행
    return 0;  //0을 return
}