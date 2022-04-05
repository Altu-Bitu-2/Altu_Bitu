#include <iostream>   //입출력 사용
#include <vector>  //vector 사용

using namespace std;  //std namespace 사용중

//LCS 길이 구하는 함수
int lcs(string str1, string str2) {  //string 2개를 인자로 하고 int를 반환하는 함수
    int n = str1.length();   //str1의 길이를 저장
    int m = str2.length();  //str2의 길이를 저장
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));  //(n+1,m+1)인 2차원 배열 0으로 초기화 - 1씩 더해주는건 인덱스를 편하게 쓰기위해
    for (int i = 1; i <= n; i++) {   //n번 반복
        for (int j = 1; j <= m; j++) {   //m번 반복
            if (str1[i - 1] != str2[j - 1]) { //두 문자가 서로 다르면
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  //위쪽과 왼쪽 중 큰 값
            }
            else if (str1[i - 1] == str2[j - 1]) { //두 문자가 서로 같다면
                dp[i][j] = dp[i - 1][j - 1] + 1;  //좌상향값 +1
            }
        }
    }
    return dp[n][m]; //LCS 길이 리턴
}

/**
 * LCS (해당 풀이는 "08. 동적계획법.pdf" 참고)
 *
 * 해당 풀이는 인덱스를 편하게 관리하기 위해 dp와 path 배열을 (1, 1)부터 시작
 */

int main() {  //main 함수
    string str1, str2;  //문자열 2개 선언

    //입력
    cin >> str1 >> str2;  //문자열2개 입력받기

    //연산 & 출력
    cout << lcs(str1, str2); //lcs
    return 0;  //0을 return
}