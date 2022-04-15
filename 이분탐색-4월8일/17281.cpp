#include <iostream>  //입출력 사용
#include <vector>  //vector 사용

using namespace std;  //std namespace 사용중

vector<vector<int>> innings;  //이닝
vector<int> order(10, 0); //타순
vector<bool> check(10, false);  //순서
int n, ans;  //정수형 변수


int hitScore(int hit, vector<bool>& baseman) {  //각 루타마다 얻는 점수
    int score = 0;  //점수 0으로 초기화
    for (int i = 3; i >= 0; i--) {  //홈 수만큼
        if (!baseman[i]) {  //해당 루에 사람없으면
            continue;  //넘어가
        }
        if (i + hit >= 4) {  //홈으로 들어올 수 있으면
            score++;  //점수 획득
        }
        else {  //hit만큼 진루
            baseman[i + hit] = true;  //해당 홈 true로
        }
        baseman[i] = false;  //원래 있던 자리는 false
    }
    if (hit == 4) {  //홈런이면
        score++;  //점수 획득
    }
    else {  //홈런 제외 친 만큼
        baseman[hit] = true; //새로운 선수들 홈에 도착
    }
    return score;  //score을 return
}


int calcScore() { //현재 배치의 점수
    int score = 0; //총 점수
    int idx = 1; //타순 저장된 order 인덱스 번호
    for (int i = 0; i < n; i++) { //i: 이닝
        vector<bool> baseman(4, 0); //각 루수마다 선수가 있는지
        int out = 0; //아웃 선수 카운트
        while (out < 3) {  //3out이 되기 전까지
            int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
            if (idx == 10) {  //10번 타자까지 갔으면
                idx = 1; // 다시 1번 타자로
            }
            if (state == 0) {  //아웃되면
                out++;  //out+1
            }
            else {  //선수가 홈에 들어오면
                score += hitScore(state, baseman);  //점수 획득
            }
        }
    }
    return score;  //score을 return
}

//가능한 배치 모두 구하기
void array(int cnt) { //cnt: 타자순서
    if (cnt == 4) { //4번 타자는 정해져 있으므로
        array(cnt + 1); //다음 타자
        return;  //함수 나오기
    }
    if (cnt == 10) { //9번 타자까지 정해짐 (기저조건)
        int score = calcScore(); //점수 계산
        ans = max(ans, score); //최대 점수를 ans에
        return;  //함수 탈출
    }
    for (int i = 2; i <= 9; i++) {  //2번부터 9번 선수
        if (!check[i]) {  //순서 안정해져있으면
            order[cnt] = i; //cnt번 타자: i번 선수
            check[i] = true; //i번 선수 순서 정해짐
            array(cnt + 1); //다음 타자
            check[i] = false;  //false로 돌려놓아주어야 한다
        }
    }
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() { //main 함수
    //입력
    cin >> n;  //이닝 수 입력받기
    innings.assign(n, vector<int>(10, 0));  //n x 10배열 생성
    for (int i = 0; i < n; i++) {  //n행
        for (int j = 1; j < 10; j++) {  //열(1~9)
            cin >> innings[i][j];  //점수 입력받기
        }
    }

    //연산
    order[4] = 1; //4번 타자는 1번 선수
    check[1] = true; //1번 선수는 순서 정해짐
    array(1);  //타자 순서 정하기

    //출력
    cout << ans; //최대 점수 출력
    return 0;  //0을 return
}