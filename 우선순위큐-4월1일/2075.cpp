#include <iostream>  //입출력 사용
#include <vector>  //vector 사용
#include <queue>  //큐 사용

using namespace std;  //std namespace 사용중

/**
 * [N번째 큰 수]
 *
 * 메모리 제한이 있으므로, 입력값을 모두 저장하면 안된다.
 * 상위 n개만 저장하는 "최소" 힙을 만들어서 heap[0]을 현재까지의 N번째 큰수로 유지하는 풀이
 */

int main() {  //main 함수
    ios::sync_with_stdio(false); //입출력 속도 향상을 위한 코드
    cin.tie(NULL);  //입출력 속도 향상을 위한 코드

    int n, input;  //정수형 변수 선언
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙, 정렬이랑 반대

    cin >> n;  //n값 입력받기
    int size = n * n;  //size는 n의 제곱
    while (size--) {  //size가 0이 될때까지
        //입력
        cin >> input;  //값 입력받기

        //연산
        pq.push(input);  //priority_queue에 값 집어넣기
        if (pq.size() > n) { //최소 힙의 크기가 n 이상이라면 가장 작은 값 삭제
            pq.pop(); //젤 작은 값 삭제
        }
    }

    //출력
    cout << pq.top();  //n번째로 큰값 출력
    return 0; //0을 return
}