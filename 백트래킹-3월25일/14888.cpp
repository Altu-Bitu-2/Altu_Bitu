#include <iostream>  //입출력 사용
#include <vector>  //vector 사용
 
using namespace std;  //std namespace 사용중
const int INF_MAX = 1e9;  //10^9
const int SIZE = 11;  //SIZE 11로 고정

int n;  //정수형 변수 선언
vector<int> num(SIZE + 1);  //크기 12인 vector 선언
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX;  //최댓값 최솟값 초기화

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum);  //더 큰수로 최댓값 업데이트
        min_value = min(min_value, sum);  // 더 작은수로 최솟값 업데이트
        return;  //함수 탈출
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) {  //연산자 존재하면
            expression[i]--;  //해당 연산자-1
            int new_sum = 0;  //계산 결과
            switch (i) { //연산자 종류에 따라
            case 0:  //+일 경우
                new_sum = sum + num[cnt + 1];  //값 더하기
                break;  //switch문 나오기
            case 1:  //-일 경우
                new_sum = sum - num[cnt + 1];  //값 빼기
                break;  //switch문 나오기
            case 2:  //*일 경우
                new_sum = sum * num[cnt + 1];  //값 곱하기
                break;  //switch문 나오기
            case 3:  // /일 경우
                new_sum = sum / num[cnt + 1];  //값 나누기
                break;  //switch문 나오기
            }
            backtracking(cnt + 1, new_sum);  //재귀함수 호출
            expression[i]++;  //줄였던 연산자 개수 다시 늘려줌
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {  //main 함수
    //입력
    cin >> n;  //입력 받기
    for (int i = 0; i < n; i++) {//n번 반복
        cin >> num[i];  //num에 숫자들 입력받기
    }
    for (int i = 0; i < 4; i++) {  //4번만 반복
        cin >> expression[i];  //연산자들 입력받기
    }

    //연산
    backtracking(0, num[0]);  //함수 호출

    //출력
    cout << max_value << '\n' << min_value;  //최댓값, 최솟값 출력
    return 0;  //0을 return
}