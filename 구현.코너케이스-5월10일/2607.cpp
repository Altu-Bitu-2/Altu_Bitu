#include <iostream> //입출력 사용
#include <vector> //vector 사용

using namespace std;  //std namespace 사용중
const int SIZE = 26; //size 고정

vector<int> alphaMap(string str) { //알파벳별 등장횟수 저장
    vector<int> result(SIZE, 0); //알파벳 배열 0으로 초기화
    for (int i = 0; i < str.size(); i++) { //스트링 길이만큼 반복
        result[str[i] - 'A']++; //등장 횟수+1
    }
    return result; //result배열 return
}

/**
 * [비슷한 단어]
 *
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */

int main() { //main함수
    int n, ans = 0;  //정수형 변수 초기화
    string source, target; //스트링 변수

    cin >> n >> source;//입력

    vector<int> source_alpha = alphaMap(source);     //연산
    while (--n) { //먼저 빼고 시작
        cin >> target; ///문자열 입력받기

        int diff = 0; //0으로 초기화
        vector<int> target_alpha = alphaMap(target); //문자열의 알파벳 등장 횟수
        for (int i = 0; i < SIZE; i++) { //두 단어의 차이
            diff += abs(source_alpha[i] - target_alpha[i]); //a부터z까지 차이들 다 더하기
        }
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) { //문자를 더하거나, 빼거나, 바꾸거나
            ans++; //답 개수 +1
        }
    }

    cout << ans; //출력
    return 0;//0을 return
}