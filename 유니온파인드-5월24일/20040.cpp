#include <iostream> //입출력 사용
#include <vector> //vector 사용

using namespace std; //std namespace 사용중

vector<int> parent; //vector 선언

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
 * [사이클 게임]
 *
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */
 
int main() { //main함수
    int n, m, x, y; //정수형 변수

    cin >> n >> m; //입력
    parent.assign(n, -1); //-1로 초기화
    for (int i = 0; i < m; i++) { //m번 반복
        cin >> x >> y; //입력받기

        if (!unionInput(x, y)) { //사이클이 생성됨
            cout << i + 1; //0부터 시작했으니까 1더해서 출력
            return 0; //0을 return
        }
    }
    cout << 0; //0 출력
    return 0; //0을 return
}

