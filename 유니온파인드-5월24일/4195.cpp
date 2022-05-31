#include <iostream> //입출력 사용
#include <vector> //vector 사용
#include <map> //map 사용

using namespace std; //std namespace 사용중
const int MAX = 2e5; //친구 관계가 모두 다른 사용자로 들어왔을 때의 정점 최댓값

vector<int> parent(MAX + 1, -1); //vector -1로 초기화
map<string, int> people; //key: string, value: int

int findParent(int node) { //Find 연산
    if (parent[node] < 0) { //음수면 본인이 부모인거
        return node; //번호 리턴
    }
    return parent[node] = findParent(parent[node]); //부모로 바꿔주기
}

bool unionInput(int x, int y) { //Union 연산
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) { //둘이 같으면
        return false; //사이클 생긴거임
    }
    if (parent[xp] < parent[yp]) { //새로운 부모 xp
        parent[xp] += parent[yp]; //yp크기 더해주기
        parent[yp] = xp; //새로운 부모 xp
    }
    else {
        parent[yp] += parent[xp]; //xp크기 더해주기
        parent[xp] = yp; //새로운 부모 yp
    }
    return true; //사이클 안생긴거임
}

/**
 * [친구 네트워크]
 *
 * 1. weighted union find -> 루트 정점에 친구의 수(집합 원소 수) 저장
 * 2. 친구 네트워크에 몇 명 있는지 구하기 -> 루트 정점의 parent값 접근
 *
 * !주의! 정점이 문자열로 들어오므로 map을 활용해 string을 int로 매핑
 */
 
int main() { //main함수
    ios_base::sync_with_stdio(false); //입출력 속도 향상
    cin.tie(NULL); //입출력 속도 향상
    cout.tie(NULL); //입출력 속도 향상

    int t, f; //정수형 변수
    string a, b; //문자열 변수

    cin >> t; //테스트케이스 수
    while (t--) { //테스트케이스 수가 0이 아닐때까지
        int idx = 1; //정점과 매핑할 수
        parent.assign(MAX + 1, -1); //-1로 초기화

        cin >> f; //친구관계 수
        while (f--) { //친구관계 수 0이 아닐때까지
            cin >> a >> b;//입력받기
            if (!people[a]) {  //처음 들어온 친구 이름일때
                people[a] = idx++; //매핑
            }
            if (!people[b]) { //처음 들어온 친구 이름일때
                people[b] = idx++; //매핑
            }

            //연산
            int x = people[a], y = people[b]; //정수형 변수
            unionInput(x, y); //유니온파인드 실행

            //출력
            cout << -parent[findParent(x)] << '\n'; //-로 나오니까 -처리해서 출력
        }
    }
    return 0; //0을 return
}
