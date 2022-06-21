#include <iostream> //입출력 사용
#include <vector>//vector 사용

using namespace std; //std namespace 사용중

vector<int> changeSwitchBoy(int n, int number, vector<int> switches) { //남학생의 스위치 바꾸기
    for (int i = number; i <= n; i += number) { //배수에 있는 스위치 바꾸기
        switches[i] = !switches[i]; //바꾸기
    }
    return switches; //바뀐 스위치 배열 return
}

vector<int> changeSwitchGirl(int n, int number, vector<int> switches) { //여학생의 스위치 바꾸기
    switches[number] = !switches[number]; //받은 수 스위치는 무조건 바뀜
    for (int i = 1; i < number; i++) { //1부터 받은 수-1까지만 check
        if ((number + i > n) || (switches[number - i] != switches[number + i])) { //스위치 범위 넘어가거나 좌우 대칭이 아니면
            break; //다음 for문으로
        }
        switches[number - i] = !switches[number - i]; //받은수 앞쪽 바꾸기
        switches[number + i] = !switches[number + i]; //받은수 뒤쪽 바꾸기
    }
    return switches; //바뀐 스위치 배열 return
}

/**
 * [스위치 켜고 끄기]
 *
 * 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 * 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기
 *
 * 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 * 스위치 20개씩 출력하는 부분 주의
 */
int main() { //main함수
    int n, m; //정수형 변수들
    int student, number; //정수형 변수들

    //입력
    cin >> n; //스위치 개수
    vector<int> switches(n + 1, 0); //스위치 상태 배열
    for (int i = 1; i <= n; i++) { //반복
        cin >> switches[i]; //입력받기
    }

    //입력 & 연산
    cin >> m; //학생수
    while (m--) { //학생 수만큼 반복
        cin >> student >> number; //성별과 받은 수 입력
        if (student == 1) { //남학생
            switches = changeSwitchBoy(n, number, switches); //바뀐 스위치 배열 받기
        }
        else { //여학생
            switches = changeSwitchGirl(n, number, switches); //바뀐 스위치 배열 받기
        }
    }

    //출력
    for (int i = 1; i <= n; i++) { //반복
        cout << switches[i] << ' '; //출력
        if (i % 20 == 0) { //20개씩 출력하기 위함
            cout << '\n';//줄바꿈
        }
    }
    return 0; //0을 return
}