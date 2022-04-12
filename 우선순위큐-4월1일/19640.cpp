#include <iostream>  //입출력 사용
#include <queue>  //큐 사용
#include <vector>  //vector 사용

using namespace std;  //std namespace 사용중

struct info {  //정수형 값들을 가지는 struct 선언
    int d, h, order, line; //근무 일수, 급한 정도, 도착한 순서, 줄 번호
};

struct cmp {  //priority_queue 기준 바꿔주기
    bool operator()(const info& a, const info& b) {  //b가 우선이라고 생각
        if (a.d != b.d) { //근무일수 다를 때
            return a.d < b.d;  //근무일수 많은게 우선
        }
        if (a.h != b.h) { //근무일수는 같고 급한정도 다를 때
            return a.h < b.h;  //급한정도가 큰게 우선
        }
        return a.line > b.line;  //줄번호는 작은게 우선
    }
};

int simulation(vector<queue<info>>& people_line, int& k) {   //vector와 정수를 인자로 갖는 함수
    int ans = 0; //ans 0으로 초기화
    priority_queue<info, vector<info>, cmp> pq; //각 줄 선두들만 저장하는 우선순위 큐

    for (int i = 0; i < people_line.size(); i++) {  //m번 반복
        if (!people_line[i].empty()) { //해당 줄(i)에 사람이 있으면
            pq.push(people_line[i].front());  //해당 줄 맨 앞 사람 우선순위 큐에 넣기
            people_line[i].pop();  //우선순위 큐에 들어간 사람 삭제
        }
    }

    while (pq.top().order != k) { //데카 순서 올때까지
        ans++;  //ans+1

        info people = pq.top(); //우선순위 젤 앞에있는 사람을 people이라한다
        pq.pop(); //우선순위 사람 삭제
        if (!people_line[people.line].empty()) { //해당 줄에 사람이 있으면
            pq.push(people_line[people.line].front()); //해당 줄 맨 앞 사람 우선순위 큐에 넣기
            people_line[people.line].pop(); //우선순위 큐에 들어간 사람 삭제
        }
    }
    return ans;  //ans을 return
}

/**
 * [화장실의 규칙] - 시뮬레이션 문제
 *
 * 1. 각 사람은 온 순서 % m 번째 줄의 뒤에 서게 된다.
 * 2. 매 순간, 모든 줄의 앞 사람 중에 우선 순위가 가장 높은 사람부터 화장실을 이용한다.
 *
 * <우선순위>
 * 1. 근무 일자가 많은 사람
 * 2. 더 급한 사람
 * 3. 줄 번호가 앞선 사람
 *
 * ---
 * 1. 각 줄은 먼저 온 사람이 먼저 나가기 때문에, 큐를 이용해 저장한다.
 * 2. 모든 줄의 선두를 우선순위 큐에 넣고, 우선순위가 가장 앞선 사람부터 삭제한다.
 * 3. 어떤 줄의 선두가 화장실을 이용했으면, 그 줄의 선두를 우선 순위 큐에 넣는다.
 *
 * 이때, 0번부터 표기하므로 데카의 order는 k가 된다.
 *
 * !주의! 큐에서 사람을 빼서 우선 순위 큐에 넣을 때, 항상 큐가 비어있지 않은지 확인
 */

int main() {  //main함수
    int n, m, k, d, h; //정수형 변수 선언

    //입력
    cin >> n >> m >> k; //입력 받기
    vector<queue<info>> people_line(m, queue<info>());  //struct로 구성된 queue들로 이루어진 vector선언
    for (int i = 0; i < n; i++) {  // n번 반복
        cin >> d >> h;  //근무일수,급한정도 입력받기
        people_line[i % m].push({ d, h, i, i % m });  //m개의 줄에 사람들 집어넣기
    }

    //연산 & 출력
    cout << simulation(people_line, k);  //함수 결과 출력
    return 0; //0을 return
}