#include <iostream>  //입출력 사용
#include <algorithm> //sort 사용
#include <vector>  //vector 사용

using namespace std; //std namespace 사용중

bool isGood(vector<int>& num, int left, int right, int idx) { //좋은 수인지 검사하는 함수(투 포인터)
    while (left < right) {  //left가 right보다 작은동안만 진행
        if (left == idx) {  //만드려는 수 위치와 left위치 같으면
            left++;  //left+1
            continue; //다음 while문으로
        }
        if (right == idx) { //만드려는 수 위치와 right위치 같으면
            right--;  //right-1
            continue;  //다음 while문으로
        }

        if (num[left] + num[right] == num[idx]) {  //left 해당 값과 right해당 값의 합이 만드려는 수와 같으면
            return true;  //true를 return
        }
        if (num[left] + num[right] > num[idx]) {  //합이 만드려는 수보다 크면
            right--; //right-1
        }
        else {  //합이 만드려는 수보다 작으면
            left++; //left+1
        }
    }
    return false;  //false를 return
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {  //main 함수
    int n, ans = 0;  //정수형 변수

    //입력
    cin >> n; //입력받기
    vector<int> num(n, 0); // 수 리스트
    for (int i = 0; i < n; i++) {  //n번 반복
        cin >> num[i];  //입력받기
    }

    //연산
    sort(num.begin(), num.end());  //오름차순 정렬
    for (int i = 0; i < n; i++) {  ///n번 반복
        if (isGood(num, 0, n - 1, i)) {  //좋다 인지 판별
            ans++;  //개수+1
        }
    }

    //출력
    cout << ans;  //출력
    return 0; //0을 return
}