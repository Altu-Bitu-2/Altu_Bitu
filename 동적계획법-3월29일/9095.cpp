#include <iostream>  //입출력 사용
#include <vector> //vector 사용

using namespace std;  //std namespace 사용중
const int MAX = 10;  //MAX를 상수 10으로 고정시켜놓음

//bottom-up 방식 dp 배열 채우기
vector<int> numberOfAllCases() {  //vector<int>를 반환하는 함수
    vector<int> dp(MAX + 1, 0);  //인덱스 10까지 사용할거니까 MAX+1크기로 vector 설정

    dp[0] = dp[1] = 1;  //0과 1일때 1로 초기화
    dp[2] = 2;  //2일때는 두가지 수
    for (int i = 3; i <= MAX; i++) {  //3부터 MAX까지
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];  //해당 인덱스들에 +1, +2, +3함
    }
    return dp;  //vector<int> return
}

/**
 * [bottom-up 접근]
 * 각 수를 인덱스로 써서 정수 n까지 1, 2, 3의 합으로 나타내는 방법의 수를 저장하자!
 *
 * 우선 3까지 1, 2, 3의 합으로 나타내는 방법의 수 초기화 함
 * 해당 인덱스에서 -1, -2, -3 한 인덱스에 +1, +2, +3을 해줬다고 생각하면 됨
 *
 * -> dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3] (n >= 3)
 *
 * 해당 풀이는 인덱스 관리를 편하게 하기 위해 0을 더미 인덱스로 줘서 인덱스 3부터 연산
 * 테스트케이스로 입력이 들어오고, 입력 범위가 11로 작기 때문에 미리 dp 배열 채우고 시작하는 것이 더 효율적
 */

int main() {  //main 함수
    int t, n;  //정수형 변수 선언

    //미리 dp 채우기
    vector<int> dp = numberOfAllCases();  //미리 vector에 값 다 채워놓기

    //입력
    cin >> t;  //testcase 수 입력받기
    while (t--) {  //t가 0이 될때까지
        cin >> n;  //수 입력받기

        //출력
        cout << dp[n] << '\n';  //해당 가짓수 출력
    }
    return 0; //0을 return
}