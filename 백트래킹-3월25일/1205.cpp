#include <iostream>   //입출력 사용
#include <vector>  //vector 사용

using namespace std;  //std namespace 사용

int findRanking(int n, int new_score, int p, vector<int>& ranking) {  //랭킹 찾아주는 함수
    int idx = 1;  //인덱스 탐색하기위한 변수
    int ans = 1;  //등수
    //새로운 점수를 어느 위치에 넣을지 탐색
    while (idx <= n) {  //리스트에 있는 점수들 탐색
        if (new_score > ranking[idx]) { //랭킹 값보다 크면
            break;  //while문 나가
        }
        if (new_score < ranking[idx]) {  //랭킹값보다 작으면
            ans = idx + 1;  //다음 순위로 내려가
        }
        idx++;  //다음 인덱스로
    }
    if (idx == p + 1) { //랭킹 리스트에 들어가지 못하는 경우
        return -1;  //-1을 return
    }
    return ans;  //등수 return
}

/**
 * [등수 구하기]
 *
 * 1. n = 0일 때, 고려
 * 2. 등수는 p보다 작지만, 점수가 더 좋을 때만 랭킹이 갱신되므로 랭킹 리스트에 들어가지 못하는 경우 고려 (동점)
 *
 * 현재 랭킹에 올라간 n까지 등수와 새로운 점수를 비교하며 새로운 점수 몇 등인지 계산
 * 새로운 점수가 현재 탐색 등수의 점수보다 작다면 -> 현재 탐색 등수 + 1
 * 동점일 경우 -> 그 전 등수 그대로 사용 -> 아무 처리도 하지 않음!
 */

int main() {  //main함수
    int n, new_score, p;  //정수형 변수들 선언

    //입력
    cin >> n >> new_score >> p;  //입력받기
    vector<int> ranking(p + 1, 0);  //int형 vector 0으로 초기화
    for (int i = 1; i <= n; i++) {  //n번 반복
        cin >> ranking[i];  //원래 ranking 값 받기
    }

    //연산 & 출력
    cout << findRanking(n, new_score, p, ranking);   //등수 출력
    return 0;  //0을 return
}