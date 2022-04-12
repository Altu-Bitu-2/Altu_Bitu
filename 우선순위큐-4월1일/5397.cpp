#include <iostream> //입출력 사용
#include <deque>  //덱 사용

using namespace std;  //std namespace 사용중

string dqToString(deque<char>& dq) {  //문자형 덱을 인자로 받는 함수
    string ans = "";  //문자형 변수
    while (!dq.empty()) {  //덱이 비어 있지 않으면
        ans += dq.front();  //덱의 앞에서부터 값꺼내기
        dq.pop_front();  //덱 앞의 값 지우기
    }
    return ans;  //ans을 return
}

string findPass(string s) {  //문자열을 인자로 받고 문자열을 return하는 함수
    deque<char> dq_left;  //커서 이전 내용을 저장
    deque<char> dq_right; //커서 이후 내용을 저장

    for (int i = 0; i < s.length(); i++) { //문자열 길이만큼 반복
        switch (s[i]) {  //s[i]를 check함
        case '-': //현재 커서 앞에 있는 글자를 지운다.
            if (!dq_left.empty()) {  //왼쪽부분을 저장하는 덱이 비어있지 않으면
                dq_left.pop_back();  //왼쪽부분 덱의 마지막 값을 pop
            }
            break;  //switch문 탈출
        case '<': //커서를 왼쪽으로 이동 -> dq_left 의 마지막 원소를 dq_right 앞에 삽입
            if (!dq_left.empty()) {  //왼쪽부분을 저장하는 덱이 비어있지 않으면
                dq_right.push_front(dq_left.back());  //왼쪽 덱의 마지막 원소를 오른쪽 덱 앞에 push
                dq_left.pop_back();  //왼쪽 덱의 마지막 원소는 pop
            }
            break;  //switch문 탈출
        case '>': //커서를 오른쪽으로 이동 -> dq_right 의 처음 원소를 dq_left 의 마지막에 삽입
            if (!dq_right.empty()) { //오른쪽 부분을 저장하는 덱이 비어있지 않으면
                dq_left.push_back(dq_right.front());  //오른쪽 덱의 앞 원소를 왼쪽 덱의 마지막에 삽입
                dq_right.pop_front(); //오른쪽 덱의 마지막 원소는 pop
            }
            break;  //switch문 탈출
        default: //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 dq_left에 삽입
            dq_left.push_back(s[i]);
            break;  //switch문 탈출
        } 
    }

    string pass = dqToString(dq_left);   //왼쪽 덱 문자들을 먼저 답 문자열에 더한다
    pass += dqToString(dq_right);  //이어서 오른쪽 덱 문자들도 더해준다
    return pass;  //답을 return
}

/**
 * [키로거]
 *
 * 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함
 *
 * 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 * 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 * 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
 */

int main() {  //main함수
    int t;  //정수형 변수
    string s;  //문자형 변수

    //입력
    cin >> t;  //입력받기
    while (t--) {  //케이스 수가 0이 될때까지
        cin >> s;  //문자열 입력받기

        //연산 & 출력
        cout << findPass(s) << '\n';  //함수 실행 결과 출력
    }
    return 0;  //0을 return
}