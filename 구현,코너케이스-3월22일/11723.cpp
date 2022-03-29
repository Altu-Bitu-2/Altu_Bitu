#include <iostream>   //입출력 사용
#include <vector>  //vector 사용
#include <string>  //string관련 함수 사용

using namespace std;   //namespace std 사용중
const int SIZE = 21;   //SIZE값을 상수 21로 설정

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {    //main함수
    ios::sync_with_stdio(false);    //c++의 입출력 속도 향상을 위해 사용
    cin.tie(NULL);  //c++의 입출력 속도 향상을 위해 사용
    
    int m, num;   //정수형 변수 선언
    string cmd;   //문자형 변수 선언
    vector<bool> s(SIZE, false);   //크기가 SIZE인 bool형 vector를 선언, 값들은 false로 모두 초기화

    cin >> m;   //입력 받기
    while (m--) {   //m이 0이 될때까지
        cin >> cmd;   //string 입력받기
        if (cmd == "all") {     //입력이 all이면
            s.assign(SIZE, true);    //string s를 모두 true로 다시 할당
            continue;   //다음 while문으로 넘어가
        }
        if (cmd == "empty") {   //입력이 empty이면
            s.assign(SIZE, false);   //string s를 모두 false로 다시 할당
            continue;   //다음 while문으로 넘어가
        }

        cin >> num;   //숫자까지 입력받아
        if (cmd == "add") {   //입력이 add이면
            s[num] = true;   //해당 숫자에 해당하는 배열값을 true로
            continue;  //다음 while문으로 넘어가
        }
        if (cmd == "remove") {  //입력이 remove이면
            s[num] = false;   //해당 숫자에 해당하는 배열값을 false로
            continue;   //다음 while문으로 넘어가
        }
        if (cmd == "check") {  //입력이 check이면(출력을 하는 부분)
            cout << s[num] << '\n'; //bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;   //다음 while문으로 넘어가
        }
        if (cmd == "toggle") {   //입력이 toggle이면
            s[num] = !s[num];    //원래 값과 반대로 바꾸기
            continue;  //다음 while문으로 넘어가
        }
    }
    return 0;   //0을 return
}