#include <iostream> //입출력 사용
#include <vector> //vector 사용
#include <tuple> //튜플 사용
#include <algorithm> //sort()사용

using namespace std; //std namespace 사용중
typedef tuple<int, int, int> tp; //3개의 정수를 튜플로 선언

vector<int> parent; //부모 배열

int findParent(int x) {  //Find 연산
    if (parent[x] < 0) { //root이면
        return x; //x를 return
    }
    return parent[x] = findParent(parent[x]); //부모 찾아서 바꿔주기
}

bool unionNodes(int x, int y) { //Union 연산
    int px = findParent(x); //px에는 x의 부모
    int py = findParent(y); //py에는 y의 부모

    if (px == py) { //부모 같으면
        return false; //false return
    }
    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py]; //더해주고
        parent[py] = px; //부모 바꿔주기
    }
    else { //새로운 루트 py
        parent[py] += parent[px]; //더해주고
        parent[px] = py; //부모 바꿔주기
    }
    return true; //true return
}

int kruskal(int n, vector<tp>& edge) { //크루스칼 함수
    int sum = 0, cnt = 0; //0으로 초기화
    for (int i = 0; i < edge.size(); i++) { // 케이블 개수만큼 반복
        int w = get<0>(edge[i]); //튜플의 첫번째 수
        int u = get<1>(edge[i]); //튜플의 두번째 수
        int v = get<2>(edge[i]); //튜플의 세번째 수
        if (!unionNodes(u, v)) { //unionNodes()가 false인 경우
            continue; //다음 for문으로
        }
        sum += w; //비용 더하기
        cnt++; //cnt+1
        if (cnt == n - 1) { //n-1번 했으면
            return sum; //비용 합 return
        }
    }
    return 0; //0을 return
}

/**
 * [전기가 부족해]
 *
 * 모든 도시에 전기가 공급될 수 있도록 최소 비용으로 도시를 연결하는 문제
 * 이 문제는 k개의 최소신장트리를 만들어야 하지만, 발전기가 있는 도시를 모두 가상의 정점에 연결한다고 생각하면 하나의 큰 트리를 이룸
 *
 * -> 한번의 크루스칼 알고리즘으로 해결 가능
 */
int main() { //main 함수
    int n, m, k, u, v, w; //정수형 변수들

    cin >> n >> m >> k; //입력
    vector<tp> edge; //튜플 배열
    parent.assign(n + 1, -1); //부모 배열 초기화
    for (int i = 0; i < k; i++) { //발전소 개수만큼 반복
        cin >> u; //입력
        parent[u] = 0; //0번 정점과 연결됐다고 생각
    }
    while (m--) { //케이블 수만큼 반복
        cin >> u >> v >> w; //입력
        edge.push_back({ w, u, v }); //값 넣기
    }

    //연산
    sort(edge.begin(), edge.end()); //정렬

    //연산 & 출력
    cout << kruskal(n - k + 1, edge); //k개의 정점은 이미 연결된 상태이므로 n - k개의 간선만 선택해도 됨
    return 0; //0을 return
}