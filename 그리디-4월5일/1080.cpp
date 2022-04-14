#include <iostream>  //입출력 사용
#include <vector>  //vector 사용

using namespace std;  //std namespace 사용중

//부분 행렬 원소 뒤집는 함수
void reverseMtx(int row, int col, vector<string>& matrix_a) {   //정수형 변수들과 vector을 인자로 받는 함수
    for (int i = row; i < row + 3; i++) {   //3*3
        for (int j = col; j < col + 3; j++) {  //3*3
            if (matrix_a[i][j] == '1') {   //1이면
                matrix_a[i][j] = '0';  //0으로
            }
            else {  //0이면
                matrix_a[i][j] = '1';  //1으로
            }
        }
    }
}

//마지막으로 A == B인지 확인하는 함수
int isPossible(int n, int m, vector<string>& matrix_a, vector<string>& matrix_b) {   //정수들과 vector을 인자로 받는 함수
    for (int i = 0; i < n; i++) {  //행
        for (int j = 0; j < m; j++) {  //열
            if (matrix_a[i][j] != matrix_b[i][j]) {  //다른 부분이 하나라도 있으면
                return false;  //행렬이 둘이 다름
            }
        }
    }
    return true;  //끝까지 다 돌았는데 다른 부분 없으면 true
}

/**
 * [행렬]
 *
 * (0, 0) 인덱스부터 부분행렬을 만들 수 있는 마지막 인덱스까지 검사하며 그리디하게 푸는 문제
 * A, B 행렬의 현재 인덱스 값이 서로 다르다면 A 행렬에서 현재 인덱스로 '시작'하는 3x3 크기만큼의 부분 행렬 원소 뒤집기
 * 검사가 모두 끝난 후, A와 B가 서로 다르다면 바꿀 수 없는 경우임
 * !주의! 입력이 공백없이 주어지므로 string으로 받음
 */

int main() {  //main함수
    int n, m;  //정수형 변수 선언

    //입력
    cin >> n >> m;  //가로 세로 값 입력받기
    vector<string> matrix_a(n);  //문자열 vector 행 수만큼 생성
    vector<string> matrix_b(n); //문자열 vector 행 수만큼 생성
    for (int i = 0; i < n; i++) { //n번 반복
        cin >> matrix_a[i];  //한줄씩 통째로 string으로 입력받기
    }

    for (int i = 0; i < n; i++) {  //n번 반복
        cin >> matrix_b[i];  //한줄씩 통째로 string으로 입력받기
    }

    //연산
    int ans = 0; //연산 횟수 저장할 변수 선언
    for (int i = 0; i <= n - 3; i++) {  //3*3이니까 n-3까지
        for (int j = 0; j <= m - 3; j++) {  //3*3이니까 m-3까지
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)원소가 서로 다르다면
                reverseMtx(i, j, matrix_a);  //뒤집기
                ans++;  //연산 횟수+1
            }
        }
    }

    //출력
    if (!isPossible(n, m, matrix_a, matrix_b)) {  //뒤집었는데 같아지지 않으면
        ans = -1;  //-1을 출력
    }
    cout << ans;  //연산 횟수 출력
    return 0;  //0을 return
}