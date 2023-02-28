#include <iostream> //입출력 사용

using namespace std; //std namespace 사용중

struct node_info { //구조체 선언
    int data; //노드 값
    node_info* left; //왼쪽 자식
    node_info* right; //오른쪽 자식
};

node_info* makeTree(node_info* node, int data) { //트리 만드는 함수
    if (node == NULL) { //이번 노드가 들어가게될 위치
        node = new node_info(); //동적 할당
        node->data = data; //노드 값
        node->left = node->right = NULL; //새로운 노드니까 자식 없음
    }
    else if (node->data > data) { //이번 값이 더 크면
        node->left = makeTree(node->left, data); //다시 tree만들어서 다 왼쪽에 넣음
    }
    else if (node->data < data) { //이번 값이 작으면
        node->right = makeTree(node->right, data); //tree만들어서 오른쪽에 넣음
    }
    return node; //node를 return
}

void postorder(node_info* node) { //후위 순회
    if (node == NULL) { //끝까지 갔으면
        return; //return
    }
    postorder(node->left); //왼쪽 먼저
    postorder(node->right); //그 다음 오른쪽 
    cout << node->data << '\n'; //마지막에 루트
}

/**
 * 맵과 셋 PPT 중 BST 노드 삽입 과정 참고
 *
 * [이진 검색 트리]
 *
 * 1. 포인터로 왼쪽, 오른쪽 서브트리를 가리키는 구조체 선언
 * 2. NULL 만날 때까지 조건에 따라 왼쪽 또는 오른쪽으로 이동
 * 3. 노드가 들어갈 위치를 찾으면 동적할당 후 노드 만들기
 * 4. 완성한 트리를 후위 순회
 */

int main() { //main 함수
    int input; //정수형 변수

    //입력 & 연산
    node_info* root = NULL; //루트 생성
    while (cin >> input) { //전위순회로 준 트리 입력받기
        root = makeTree(root, input); //트리 만들기
    }

    //출럭
    postorder(root); //후위순회로 출력
    return 0; //0을 return
}