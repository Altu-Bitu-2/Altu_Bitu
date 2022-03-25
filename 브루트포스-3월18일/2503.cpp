#include <iostream>  //입출력 기능 사용
#include <vector>  //vector 사용
#include<string> //to_string 사용

using namespace std;   //std namespace 사용중
typedef pair<int, int> ci;    //(int, int)쌍을 인자로 가지는 pair을 선언(스트라이크와 볼 수를 의미할 것임)

struct baseball {   //string과 int를 가지는 structure 정의
    string num;       //서로 다른 세 자리 수
    int strike, ball; //스트라이크 개수, 볼 개수
};

ci cntStrikeBall(string& s1, string& s2) {    //strike와 ball 수를 return해주는 함수
    int strike_cnt = 0; //s1과 s2사이의 strike 개수
    int ball_cnt = 0;   //s1과 s2사이의 ball 개수

    for (int i = 0; i < 3; i++) {  //세자리 수니까 세번 반복
        if (s1[i] == s2[i]) { //위치+수 정확히 일치 -> 스트라이크
            strike_cnt++;  //strike수 +1
        }
        else if (s1.find(s2[i]) != s1.npos) { //위치 다른데 수가 존재 -> 볼
            ball_cnt++;   //ball수 +1
        }
    }

    return ci(strike_cnt, ball_cnt); //ci쌍 return
}

int game(int n, vector<baseball>& question) {  //될 수 있는 정답 개수를 return해주는 함수
    int ans = 0; //정답 개수

    for (int i = 123; i <= 987; i++) {  //123부터 987까지  반복
        bool check = true;  //i에 해당하는 수가 정답이 될 수 있는지 check하기 위한 boolean
        string s1 = to_string(i);  //정답인지 확인할 수

        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') { //0이 하나라도 있다면
            continue;  //다음 for문으로 넘어가
        }
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) { //서로 같은 수 하나라도 있다면
            continue;   //다음 for문으로 넘어가
        }

        for (int j = 0; j < n; j++) {  //질문 수 n만큼 반복
            string s2 = question[j].num; //질문으로 들어온 수
            ci cnt = cntStrikeBall(s1, s2); //s1과 s2사이의 스트라이크와 볼 개수
            if (cnt.first != question[j].strike || cnt.second != question[j].ball) { //하나라도 다르면
                check = false;   //정답이 될 수 없다
                break;    //for문 더 돌릴 필요없이 바로 break
            }
        }

        if (check) {   //check이 true이면
            ans++;   //ans+1
        }
    }

    return ans;  //ans값을 return
}

/**
 * [숫자 야구]
 * 서로 다른 세 자리 수에서 위치 + 수 같으면 스트라이크, 위치는 다르고 수가 존재하면 볼
 * n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수
 *
 * [풀이]
 * 서로 다른 세 자리수는 123 ~ 987이 가능하다. 이는 총 865가지
 * 질문 n의 범위는 최대 100
 * 따라서 123부터 하나씩 증가시키며 정답이 되는지 검사해도 865 * 100 * 3(자릿수)으로 접근 충분히 가능!
 */

int main() {  //main함수
    int n;    //총 질문 수를 입력받을 n 선언

    //입력
    cin >> n;

    vector<baseball> question(n);   //사이즈가 n인 vector 선언
    for (int i = 0; i < n; i++) {   //질문 수만큼 수와 strike,ball개수를 입력받음
        cin >> question[i].num >> question[i].strike >> question[i].ball;   //값에 넣어주기
    }

    //연산 + 출력
    cout << game(n, question);   //정답 return

    return 0;   //0을 return
}