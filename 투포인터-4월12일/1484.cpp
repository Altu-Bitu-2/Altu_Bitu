#include <iostream> //입출력 사용
#include <vector>  //vector 사용

using namespace std;  //std namespace 사용중

vector<int> possibleWeight(int left, int right, int g) {  //가능한 현재 몸무게 return하는 함수
    vector<int> ans;  //가능한 몸무게들
    while (left < right) {  //left가 right보다 작을동안만 진행
        int diff = right * right - left * left;  //현재몸무게 제곱-기억하고있던몸무게 제곱

        if (diff <= g) {  //g보다 같거나 작을경우
            if (diff == g) {  //같으면
                ans.push_back(right); //가능한 몸무게
            }
            right++;  //right+1
        }
        else {  //g보다 큰 경우
            left++;  //left+1
        }
    }
    return ans;  //ans을 return
}

/**
 * [다이어트]
 *
 * left: 성원이가 기억하고 있던 몸무게
 * right: 성원이의 현재 몸무게
 *
 * 같은 위치에서 시작해서 점점 증가하는 투 포인터로 풀이
 * 대신, left ~ right를 모두 고려하는 것이 아니라 left, right 포인터 값 자체만 고려
 *
 * !주의! 몸무게의 범위가 딱히 정해져 있지 않으므로, 종료 조건을 잘 세우는 것이 중요!
 *       -> 두 몸무게가 같아지는 순간 종료!
 *       -> left가 right와 같은 값을 가진다면, 직전 상황은 두 몸무게가 1차이 나는 상황
 *       -> 이때 몸무게 차이가 g 이상이었다는 것은 이후로 나올 수 있는 차이는 무조건 g이상이 된다. (제곱수의 간격은 수가 커질수록 늘어나기 때문)
 */

int main() {  //main함수
    int g;  //정수형 변수 선언

    //입력
    cin >> g;  //입력받기

    //연산
    vector<int> ans = possibleWeight(1, 2, g);  //가능한 값들

    //출력
    if (!ans.size()) {  //size가 0이면
        cout << "-1";  //-1출력
        return 0;  //0을 return
    }
    for (int i = 0; i < ans.size(); i++) {  //size번 반복
        cout << ans[i] << '\n';  //출력
    }
    return 0;  //0을 return
}