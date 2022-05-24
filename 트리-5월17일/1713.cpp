#include <iostream>  //입출력 사용
#include <vector>  //vector 사용
#include <map>  //map 사용
#include <algorithm>  //min_element() 사용

using namespace std;  //std namespace 사용중
typedef pair<int, int> ci;  //int, int형 pair 선언

bool cmp(const pair<int, ci>& c1, const pair<int, ci>& c2) { //비교함수
    if (c1.second.first != c2.second.first) { //추천 횟수가 다르면
        return c1.second.first < c2.second.first;  //추천 횟수 오름차순으로
    }
    return c1.second.second < c2.second.second;  //추천횟수 같을 때는 게시 시간 오름차순으로
}

/**
 * [후보 추천하기]
 *
 * 1. 비어있는 사진틀이 없는 경우, 가장 추천수가 작은 학생 중 게시 시간이 오래된 학생을 삭제
 * -> min_element() 함수를 활용해서 조건을 만족하는 학생 찾기
 * -> min_element(x.begin(), x.end(), cmp): x 컨테이너 내에서 최솟값을 찾아주는 함수로 정렬과 비슷하게 cmp함수 써서 조건 설정 가능!
 *
 * 2. 후보 학생을 바로 찾기 위해 본 풀이는 map 컨테이너를 사용해 구현
 *
 * !주의! 게시 시간 정보 저장 시, 후보로 올라간 가장 첫 시간을 저장. 이미 후보에 있는데 게시 시간이 갱신되지 않도록 주의.
 */

int main() {  //main 함수
    int n, m, input;  //정수형 변수들 선언

    cin >> n >> m;   //입력 & 연산
    map<int, ci> candidate; //first: 후보 학생, second: {추천 횟수, 게시 시간}
    for (int i = 0; i < m; i++) { //m번 반복
        cin >> input; //입력받기
      
        if (candidate.size() == n && candidate.find(input) == candidate.end()) {   //비어있는 사진틀이 없는 경우
            candidate.erase(min_element(candidate.begin(), candidate.end(), cmp));  //추천 횟수 또는 게시 시간으로 삭제될 학생 선택하고 지우기
        }
       
        if (candidate.find(input) == candidate.end()) {  //첫 게시라면
            candidate[input].second = i;  //게시 시간 i로 넣기
        }
        candidate[input].first++; //추천 횟수 증가
    }

    for (auto iter = candidate.begin(); iter != candidate.end(); iter++) { //candidate begin부터 end까지 반복
        cout << iter->first << ' '; //출력
    }
    return 0; //0을 return
}