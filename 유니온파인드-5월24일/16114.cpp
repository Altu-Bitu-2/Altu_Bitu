#include <iostream> //입출력 사용
#include<string> //to_string()사용

using namespace std; //std namespace 사용중

string solution(int x, int n) { //string 반환하는 함수
    if (n > 1 && n % 2 == 1) { //1번경우
        return "ERROR"; //ERROR출력
    }
    if (n == 1 && x < 0) { //2번 경우
        return "INFINITE"; //INFINITE 출력
    }
    if (n == 1 || x <= 0) { //3번 경우
        return "0"; //0 출력
    }
    if (n == 0) { //4번 경우
        return "INFINITE"; //INFINITE 출력
    }
    return to_string((x - 1) / (n / 2)); //5번 경우 string으로 반환해야하니까 to_string()이용
}

/**
 * [화살표 연산자]
 *
 * 1. n이 1보다 큰 홀수인 경우 -> ERROR
 * 2. n이 1인데 x가 음수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 3. n이 1인데 x가 양수인 경우 or x가 0보다 작거나 같은 경우 -> while문에 진입 못함 -> 0
 * 4. n이 0인데 x가 양수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 5. 나머지 경우엔 (x - 1)을 (n / 2)로 나눈 몫을 출력
 *    - 연산했을 때 1 이상이 남을 때까지만 출력을 할 수 있으므로 1을 뺀 값에서 몫을 구함
 */
 
int main() { //main함수
    int x, n; //정수형 변수

    cin >> x >> n;  //입력

    cout << solution(x, n); //연산 & 출력
    return 0; //0을 return
}