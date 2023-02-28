#include <iostream> //입출력 사용
#include <vector> //vector 사용
#include <queue> //큐 사용

using namespace std; //std namespace 사용중
typedef pair<int, int> ci; //정수,정수형 쌍 선언
const int INF = 1e5 + 1; //최댓값 고정

int prim(int size, int start, vector<vector<int>>& graph) { //prim함수
    int sum = 0; //0으로 초기화
    priority_queue<ci, vector<ci>, greater<>> pq; //우선순위 큐 선언
    vector<bool> visited(size, false); //논 방문 여부
    vector<int> dist(size, INF); //각 논까지의 비용

    dist[start] = 0; //초기화
    pq.push({ 0, start }); //초기화

    while (!pq.empty()) { //큐가 비어있지 않을 동안
        int cost = pq.top().first; //값 불러오기
        int cur = pq.top().second; //현재 논 불러오기
        pq.pop(); //삭제

        if (visited[cur]) { //방문했던 논이라면
            continue; //다음 while문으로
        }
        visited[cur] = true; //방문으로 바꿔주기
        sum += cost; //비용 더하기

        for (int i = 0; i < size; i++) { //반복
            if (!visited[i] && graph[cur][i] < dist[i]) { //방문한적 없는 논이고 비용이 더 저렴할 경우
                dist[i] = graph[cur][i]; //dist배열에 비용 갱신
                pq.push({ graph[cur][i], i }); //값과 현재 논 번호 push
            }
        }
    }
    return sum; //총 비용 return
}

/**
 * [물대기]
 *
 * 각 논들 사이의 간선도 고려하고, 우물을 파는 경우도 고려? -> 복잡
 * 논에 추가로 모든 우물과 연결되는 수원이 있다고 가정!
 * ->직접 논에 우물을 파는 경우는 수원과 각 논 사이의 간선 가중치라고 할 수 있음
 *
 * 0 2 2 2 5
 * 2 0 3 3 4
 * 2 3 0 4 4
 * 2 3 4 0 3
 * 5 4 4 3 0
 *
 * 인덱스 0 ~ n-1은 논, 인덱스 n은 수원
 * 1개 이상의 논은 반드시 직접 우물을 파야 하므로 수원(n)에서 시작하는 프림 알고리즘
 */
int main() { //main함수
    int n, w; //정수형 변수들

    cin >> n; //입력
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0)); //행렬 초기화
    for (int i = 0; i < n; i++) { //수원으로부터 물을 끌어오는 비용
        cin >> w; //입력
        graph[i][n] = graph[n][i] = w; //양쪽 방향 모두 해주기
    }

    for (int i = 0; i < n; i++) { //행
        for (int j = 0; j < n; j++) { //열
            cin >> graph[i][j]; //논들 사이에서 물을 끌어오는 비용
        }
    }

    //연산 & 출력
    cout << prim(n + 1, n, graph); //수원에서 시작하는 프림 알고리즘
    return 0; //0을 return
}