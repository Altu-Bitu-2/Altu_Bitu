#include <iostream>  //입출력 사용
#include <algorithm>  //sort 사용
#include <vector>  //vector 사용

using namespace std;  //std namespace 사용중
typedef long long ll;  //long long형으로 ll 고정

ll cntTree(int height, vector<int>& tree) {  //집에 가져갈 수 있는 나무 미터값 출력해주는 함수
    ll sum = 0;  //sum을 0으로 초기화
    for (int i = 0; i < tree.size(); i++) {  //나무 개수만큼 반복
        if (height >= tree[i]) {  //절단기 높이가 해당 나무보다 크면
            return sum;  //그냥 sum을 return
        }
        sum += (tree[i] - height);  //절단기가 나무를 자를 수 있으면 자른 값을 sum에 더한다
    }
    return sum;  //sum을 return
}

int upperSearch(int left, int right, int target, vector<int>& tree) {  //최대 절단기 높이값 출력해주는 함수
    while (left <= right) {  //left는 right이하여야 한다
        int mid = (left + right) / 2;  //중간값 설정
        ll tree_cnt = cntTree(mid, tree);  //집에 가져갈 수 있는 나무 미터값

        if (tree_cnt >= target) {  //값이 목표값보다 크면
            left = mid + 1;  //left를 mid오른쪽으로 갖고옴
        }
        else {
            right = mid - 1;  //right를 mid왼쪽으로 갖고옴
        }
    }
    return left - 1; //옆으로 넘어간 값이니까 하나 빼준다
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {  //main 함수
    int n, m;  //정수형 변수

    //입력
    cin >> n >> m;  //나무 개수와 집으로 가져가고 싶은 양 입력받기
    vector<int> tree(n, 0);  //배열 0으로 초기화
    for (int i = 0; i < n; i++) {  //나무 개수만큼 반복
        cin >> tree[i];  //나무 높이 입력받기
    }

    sort(tree.begin(), tree.end(), greater<>());  //내림차순으로 정렬

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree);  //절단기 높이 최댓값 출력
    return 0;  //0을 return
}