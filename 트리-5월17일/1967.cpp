#include <iostream> //입출력 사용
#include <vector> //vector 사용

using namespace std; //std namespace 사용중
typedef pair<int, int> ci; //int, int형 pair 선언

ci dfs(int node, int parent, vector<vector<ci>>& graph) { //pair로 return할거임
    int pos = node, len = 0; //지름을 구성하는 노드 중 하나, 그 노드까지의 거리
    for (int i = 0; i < graph[node].size(); i++) { //해당 노드 사이즈만큼만 반복
        int next_node = graph[node][i].first; //노드 번호
        if (next_node == parent) { //parent와 같다면
            continue; //다음 for문으로
        }

        ci dfs_search = dfs(next_node, node, graph); //자식 노드에 대해 dfs 탐색
        if (graph[node][i].second + dfs_search.second > len) { //기존 거리보다 길다면 갱신
            len = graph[node][i].second + dfs_search.second; //가중치 더하기
            pos = dfs_search.first; //노드 번호
        }
    }
    return { pos, len }; //노드 번호와 가중치 return
}

/**
 * [트리의 지름]
 *
 * 1. 지름을 이루는 두 점은 모두 리프 노드
 * 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 * 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드
 *
 * 부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
 */

int main() { //main 함수
    int n, p, c, w; //정수형 변수들 선언
    
    //입력
    cin >> n; //노드 개수
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //노드 개수 +1개 그리고 자식과 가중치
    for (int i = 1; i < n; i++) { //무방향 그래프로 만들기
        cin >> p >> c >> w; //입력받기
        graph[p].push_back({ c, w }); //무방향
        graph[c].push_back({ p, w }); //무방향
    }

    //연산
    ci first_node = dfs(1, -1, graph); //지름을 구성하는 노드 하나 찾기
    ci second_node = dfs(first_node.first, -1, graph); //지름을 구성하는 다른 노드 찾기

    //출력
    cout << second_node.second; //가중치 출력
    return 0; //0을 return
}