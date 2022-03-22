#include <iostream> //입출력 사용

using namespace std;  //std namespace 사용중

// 유클리드 호제법
int gcdRecursion(int a, int b) {   // 정수 a와b를 입력으로 받는 최대공약수를 구하기 위한 재귀함수
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (b == 0) {   //b가 0이면
        return a;   //a를 return
    }
    return gcdRecursion(b, a % b);    //b와 a%b로 재귀함수 다시 호출
}

int main() {
    string s;    //문자열 s 생성

    //입력
    cin >> s;

    //연산(입력으로부터 n, m 추출하기)
    int index = s.find(':'); //':' 위치 찾기
    int n = stoi(s.substr(0, index)); //: 이전의 문자를 숫자로 변경
    int m = stoi(s.substr(index + 1, s.length())); //: 이후 문자를 숫자로 변경

    //최대공약수 구하기
    int g = gcdRecursion(max(n, m), min(n, m));   //왼쪽에 a로 큰수를, 오른쪽에 b로 작은수를 넣음

    //출력
    cout << n / g << ':' << m / g << '\n';    //최대공약수로 나눈 비율을 출력

    return 0;   //0을 리턴
}