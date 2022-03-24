#include <iostream>   //입출력 사용
#include <cmath>    //sqrt() 사용

using namespace std;   //std namespace 사용중

// 유클리드 호제법
int gcdRecursion(int a, int b) {     //정수 a와 b를 입력받아 최대공약수를 리턴하는 재귀함수
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (b == 0) {   //b가 0이면
        return a;   //a를 리턴
    }
    return gcdRecursion(b, a % b);   //b와 a%b를 인자로 다시 재귀함수 호출
}

/**
 * 최대공약수를 G, 최소공배수를 L 이라고 하자.
 * G*L = A*B 이고
 * A = G*a, B = G*b로 나타낼 수 있다.
 * 이에 따라 G*L = G*G*a*b라 할 수 있고 이를 정리하면
 * L/G = a*b 이다.
 *
 * A+B가 최소가 되려면, a+b가 최소가 되어야 하고, 그러기 위해선 a, b의 차이가 최소여야 한다.
 */

int main() {
    int gcd, lcm;    //최대공약수, 최소공배수 인자 생성

    //입력
    cin >> gcd >> lcm;  //주어진 최대공약수와 최소공배수 입력받기

    //연산
    int ab = lcm / gcd;   //G*L = G*G*a*b이므로 L/G = a*b인 것을 이용
    int a = -1, b = -1;  //-1로 일단 초기화시켜놓기
    for (int i = sqrt(ab); i > 0; i--) { //a, b의 차이가 가장 작을 제곱근부터 체크
        if (ab % i != 0) {   //i가 ab의 약수가 아니라면
            continue;  //for문 계속 돌리기
        }
        //i가 ab의 약수라면
        int tmp_a = i, tmp_b = ab / i;   //a가 더 작은 수가 되도록
        //두 수가 서로소인지 체크 -> 만약 두 수가 서로소가 아니라면 두 수의 최대공약수가 gcd가 될 수 없음
        if (gcdRecursion(tmp_b, tmp_a) == 1) {   //서로소라는 의미
            a = tmp_a;    //a*gcd
            b = tmp_b;    //b*gcd
            break;   //for문 나오기
        }
    }

    //출력
    cout << a * gcd << ' ' << b * gcd;  //값 출력
}