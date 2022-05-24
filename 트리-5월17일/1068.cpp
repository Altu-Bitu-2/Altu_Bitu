#include <iostream> //입출력 사용
#include <vector> //vector 사용

using namespace std; //std namespace 사용중

vector<vector<int>> tree; //트리 배열

int eraseLeafCnt(int node, int& erase_node) { //주어진 정점을 지웠을 때의 리프 노드의 수
    if (node == erase_node) { //root가 지울 노드면 다 없어짐
        return 0; //0을 return
    }
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) { //리프 노드인 경우
        return 1; //1을 return
    }
    int cnt = 0; //개수 0으로 초기화
    for (int i = 0; i < tree[node].size(); i++) { //트리 노드 개수만큼 반복
        cnt += eraseLeafCnt(tree[node][i], erase_node); //cnt에 리프 토드 개수가 계속 더해짐
    }
    return cnt; //개수 return
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() { //main 함수
    int n, par, root, erase_node; //정수형 변수들
    
    cin >> n; //입력받기
    tree.assign(n, vector<int>(0)); //노드 개수만큼
    for (int i = 0; i < n; i++) { //n번 반복
        cin >> par; //부모 입력받음
        if (par == -1) { //-1이면
            root = i; //루트 노드임
            continue; //다음 for문
        }
        tree[par].push_back(i); //해당 parent에 자식으로 push
    }
    cin >> erase_node; //지울 노드 번호

    cout << eraseLeafCnt(root, erase_node);  //연산 & 출력
    return 0; //0을 return
}