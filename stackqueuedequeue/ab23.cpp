#include <iostream>   //입출력받기
#include <deque>  //덱 사용
#include <vector>   //vector 사용
#include <algorithm>  //reverse()사용

//문제 18115
using namespace std;   //std namespace 사용중

deque<int> cardGame(int n, vector<int>& cmd) {
    deque<int> dq;   //int형 deque 선언

    for (int i = 1; i <= n; i++) { //놓여 있는 위의 카드부터 검사 1, ..., n
        switch (cmd[i]) {   //cmd[i]값을 확인
        case 1:    //cmd[i]가 1이라면
            dq.push_front(i); //i를 deque의 앞에 삽입
            break;  //switch문 나오기
        case 2: { //!주의! c++에서 switch-case 문에 변수 선언 시 {} 필수!
            int x = dq.front();    //x에 deque의 front 값 대입
            dq.pop_front();   //  //front값을 pop
            dq.push_front(i);   //i를 front에 push
            dq.push_front(x);  //x를 front에 push
            break;   //switch문 나오기
        }
        case 3:  //cmd[i]가 3이라면
            dq.push_back(i);   //i를 마지막에 push
            break;    //switch문 나오기
        }
    }
    return dq;
}

/**
 * 결과값을 보고 처음 도출 -> 기술을 모두 반대로 쓰자!
 * 1. 제일 위의 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드를 다시 위에 ->
 *    제일 위의 카드 앞에 넣기
 * 2. 위에서 두 번째 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드 위에서 두 번째에 넣기 ->
 *    제일 위의 카드 앞에서 두번째에 넣기
 * 3. 제일 밑에 있는 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드 밑에 넣기 ->
 *    제일 위의 카드 뒤에 넣기
 */

int main() {
    int n;  //변수 n선언

    //입력
    cin >> n;
    vector<int> cmd(n + 1, 0);   //사이즈가 n+1인 vector 선언
    for (int i = 1; i <= n; i++) { //입력
        cin >> cmd[i];   //cmd[i]에 입력받은 값 넣기
    }

    //연산
    reverse(cmd.begin() + 1, cmd.end()); //가장 위의 카드부터 검사하기 위해 기술 순서도 반대로
    deque<int> dq = cardGame(n, cmd);  //cardGame의 결과값을  dq에 대입

    //출력
    while (!dq.empty()) {    //dq가 비어있을때까지
        cout << dq.front() << ' ';   //front값을 출력
        dq.pop_front();  //front 값을 pop
    }
    return 0;   //0을 return
}
