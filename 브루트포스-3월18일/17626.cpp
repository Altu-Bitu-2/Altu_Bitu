﻿#include <iostream>  //입출력 사용
#include <vector>  //vector 사용
#include <cmath>  //sqrt() 사용

using namespace std;  //std namespace 사용중

int findMinNumber(int n, int num_size, vector<int>& square_num) {    //제곱수들의 최소 개수를 return하는 함수
    if (square_num[num_size - 1] == n) { //1개로 만들 수 있을 경우 바로 리턴
        return 1;  //1을 return
    }
    for (int i = num_size - 1; i >= 0; i--) { //2개로 만들 수 있는 경우 검사(첫번째 요소)
        for (int j = num_size - 1; j >= 0; j--) {  //2개로 만들 수 있는 경우 검사(두번째 요소)
            if (square_num[i] + square_num[j] == n) {   //2개를 더한 값이 n과 같으면
                return 2;   //2를 return
            }
        }
    }
    for (int i = num_size - 1; i >= 0; i--) { //3개로 만들 수 있는 경우 검사(첫번째 요소)
        for (int j = num_size - 1; j >= 0; j--) { //3개로 만들 수 있는 경우 검사(두번째 요소)
            for (int k = num_size - 1; k >= 0; k--) {   //3개로 만들 수 있는 경우 검사(세번째 요소)
                if (square_num[i] + square_num[j] + square_num[k] == n) {   //3개를 더한 값이 n과 같으면
                    return 3;   //3을 return
                }
            }
        }
    }
    return 4;  //4를 return
}

/**
 * [Four Squares] - 브루트포스 풀이 (8ms)
 * 자연수 n에 대해 최소 몇개의 제곱수의 합으로 표현할 수 있는지 찾는 문제
 * 미리 최댓값까지의 제곱수를 구해놓고, 완전탐색
 *
 * 1 ~ 3개 조합으로 불가능한 경우, 답은 무조건 4가 된다 -> 4개의 합은 시도해보지 않아도 된다.
 *
 * sqrt(50000) = 약 223
 * 전체 연산 수  < 223^2 + 223^3 = 11139296 <1억 -> 브루트포스 가능
 */

int main() {  //main 함수
    int n, num_size;  //정형 변수 선언
    vector<int> square_num;  //정수형 vector 선언

    //입력
    cin >> n;

    //연산
    for (int i = 1; i <= sqrt(n); i++) { //미리 루트 n 까지의 제곱수 저장
        square_num.push_back(i * i);  //i의 제곱수를 vector에 저장
    }
    num_size = square_num.size(); //제곱수 개수

    //출력
    cout << findMinNumber(n, num_size, square_num);  //제곱수의 최소개수를 return
    return 0;  //0을 return
}