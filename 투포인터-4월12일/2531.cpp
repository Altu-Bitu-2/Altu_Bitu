#include <iostream> //입출력 사용
#include <vector> //vector사용

using namespace std;  //std namespace 사용중

int chooseSushi(int n, int d, int k, int c, vector<int>& belt) {  //최대 종류 수 return하는 함수
    vector<int> sushi(d + 1, 0); //초밥 먹은 개수

    //쿠폰으로 먹은 초밥
    int section_sushi = 1;  //1종류 먹음 일단
    sushi[c]++;  //쿠폰번호 초밥+1

    //윈도우 초기화
    for (int i = 0; i < k; i++) {  //k번 반복
        if (!sushi[belt[i]]) {  //먹은 적 없었던 번호 스시
            section_sushi++;  //종류+1
        }
        sushi[belt[i]]++;  //해당 번호 초밥 +1
    }

    int ans = section_sushi;  //ans에 첫번째 슬라이드 종류 개수 저장
    for (int i = k; i < n + k; i++) { //슬라이딩 윈도우
        sushi[belt[i - k]]--;  //맨 앞 스시 빼주기
        if (!sushi[belt[i - k]]) {   //해당 번호 스시 먹은게 이제 없으면
            section_sushi--;  //종류-1
        }
        if (!sushi[belt[i % n]]) {  //새로들어온 스시먹은적이 없었으면
            section_sushi++;  //종류+1
        }
        sushi[belt[i % n]]++;  //해당 번호 스시 먹었다+1
        ans = max(ans, section_sushi);  //더 큰 값으로 교체
    }
    return ans;  //ans을 return
}

/**
 * [회전 초밥]
 *
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥의 개수를 세어주기
 */

int main() {  //main함수
    int n, d, k, c;  //정수형 변수 선언

    //입력
    cin >> n >> d >> k >> c;  //입력받기
    vector<int> belt(n, 0);  //벨트 0으로 초기화
    for (int i = 0; i < n; i++) {  //n번 반복
        cin >> belt[i];  //입력받기
    }

    //연산 & 출력
    cout << chooseSushi(n, d, k, c, belt);  //출력
    return 0; //0을 return
}