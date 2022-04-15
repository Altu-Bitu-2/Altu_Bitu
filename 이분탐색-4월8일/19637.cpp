#include <iostream>  //입출력 사용
#include <map> //map 사용

using namespace std;  //std namespace 사용중

/**
 * [IF문 좀 대신 써줘]
 *
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */

int main() {  //main 함수
    ios::sync_with_stdio(false); //입출력 속도 향상시키기 위한 함수
    cin.tie(NULL);  //입출력 속도 향상시키기 위한 함수

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power;  //정수형 변수 선언
    string name;  //문자열 변수 선언

    //입력
    cin >> n >> m;  //칭호 개수와 캐릭터 개수
    while (n--) {  //칭호 개수만큼
        cin >> name >> power;  //칭호와 칭호의 상한값
        if (title[power].empty()) {  //칭호 상한값에 해당하는 value비어있으면
            title[power] = name;  //칭호 넣어주기
        }
    }

    //출력
    while (m--) { //캐릭터 개수만큼
        cin >> power;  //전투력 입력받기
        cout << title.lower_bound(power)->second << '\n';  //title map에서 power에 맞는 value 출력
    }
}