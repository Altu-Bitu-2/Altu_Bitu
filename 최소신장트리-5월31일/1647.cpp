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
    for (int i = 0; i < edge.size(); i++) { // 길 개수만큼 반복
        int w = get<0>(edge[i]); //튜플의 첫번째 수
        int u = get<1>(edge[i]); //튜플의 두번째 수
        int v = get<2>(edge[i]); //튜플의 세번째 수
        if (!unionNodes(u, v)) { //없앨 수 있는 도로일 경우
            continue; //다음 for문으로
        }
        sum += w; //길 유지비 더하기
        cnt++; //cnt+1
        if (cnt == n - 1) { //n-1번 했으면
            return sum; //유지비 합 return
        }
    }
    return 0; //0을 return
}

/**
 * [도시 분할 계획]
 *
 * 마을을 두개로 분리하고, 각 집끼리 이동할 수 있는 최소한의 도로만 남기는 문제
 * 즉, 2개의 최소신장트리를 만들어야 하는 문제
 * -> 하나의 최소신장트리를 만들고, 그 중 가장 유지비가 큰 도로를 삭제
 * -> 크루스칼 알고리즘에서 가장 마지막에 삭제되는 도로가 유지비가 가장 큼
 * -> 크루스칼 알고리즘에서 간선을 n-2개만 선택하여 그 합을 구하여 해결
 */
int main() { //main함수 
    int n, m, a, b, c; //정수형 변수들

    //입력
    cin >> n >> m; //집,길의 개수
    vector<tp> edge; //튜플 배열
    parent.assign(n + 1, -1); //부모 배열 초기화
    while (m--) { //길 개수만큼 반복
        cin >> a >> b >> c; //입력
        edge.push_back({ c, a, b }); //길에 값 넣기
    }

    //연산
    sort(edge.begin(), edge.end()); //정렬하기

    //연산&출력
    cout << kruskal(n - 1, edge); //출력
    return 0; //0을 return
}