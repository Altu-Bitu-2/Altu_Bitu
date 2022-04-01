#include <iostream>  //입출력 사용
#include <vector>  //vector 사용

using namespace std;  //std namespace 사용중
const int INF = 1e8;   //10^8

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

/**
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 */
void backtracking(int cnt, int cur_city, int cost) {   //cnt:방문한 도시 수, cur_city:현재 도시, cost: 비용
    if (cost >= ans) { //생각해보기 : 이 조건문이 없으면 어떻게 될까요? - 최소 비용이 안되는 경우에도 의미없이 계산을 다 돌게 된다..?
        return;  //함수 탈출
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) {  //0번 도시로 가는 길이 있으면
            ans = min(ans, cost + matrix[cur_city][0]);  //가고 최소비용 업데이트
        }
        return;  //함수 탈출
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true;  //i도시 방문 표시
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);   //i에서 다른 도시로 이동하기 위해 다시 함수 호출
            visited[i] = false;  //false로 돌려주기
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {  //main함수
    //입력
    cin >> n;  //도시 개수 입력받기
    visited.assign(n, false); //일단 다 미방문으로 초기화
    matrix.assign(n, vector<int>(n, 0));  //n*n matrix 초기화
    for (int i = 0; i < n; i++) {   //n행
        for (int j = 0; j < n; j++) {  //n열
            cin >> matrix[i][j];  //거리 비용 입력받기
        }
    }

    //연산
    visited[0] = true;  //0번 도시에서 출발
    backtracking(1, 0, 0);  //함수호출

    //출력
    cout << ans;  //최소비용 출력
    return 0;  //0을 return
}