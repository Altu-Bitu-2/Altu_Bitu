#include <iostream>  //입출력 사용
#include <queue>  //queue 사용
#include <vector>  //vector 사용

using namespace std;  //std namespace 사용중
typedef pair<int, int> ci;  //int형 두개로 이루어진 pair 선언

vector<bool> is_valid;  //bool형 vector 선언

//최대 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMax(priority_queue<ci>& heap) {   //pair형 priority_queue를 인자로 받는 함수(max)
    while (!heap.empty() && !is_valid[heap.top().second]) {  //heap이 비어있지 않고 top값이 valid하지 않으면
        heap.pop();  //값을 pop
    }
}

//최소 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMin(priority_queue<ci, vector<ci>, greater<>>& heap) {  //pair형 priority_queue를 인자로 받는 함수(min)
    while (!heap.empty() && !is_valid[heap.top().second]) {  //heap이 비어있지 않고 top값이 valid하지 않으면
        heap.pop();  //값을 pop
    }
}

/**
 * 우선순위 큐 풀이
 * 최대 힙과 최소 힙을 동시에 관리하면서 각각의 힙에서 삭제된 데이터를 다른 힙에 반영하는 방법
 * -> 각 데이터의 유효성을 체크하는 배열을 만들기
 */
int main() {  //main함수
    int t, k, n;  //정수형 변수 선언
    char cmd;  //문자형 변수 선언
    
    cin >> t;  //테스트 케이스 수 입력받기
    while (t--) {  //테스트 케이스 수가 0이 될때까지
        priority_queue<ci> max_heap; //최대 힙
        priority_queue<ci, vector<ci>, greater<>> min_heap; //최소 힙
        cin >> k;  //연산 수 입력받기
        int idx = 0; //I 연산으로 입력된 숫자의 인덱스
        while (k--) { //연산 수가 0이 될때까지
            //입력
            cin >> cmd >> n;  //입출력과 수 받기

            //연산
            switch (cmd) {  //cmd를 확인
            case 'I': //두가지 힙 모두에 값을 넣은 뒤, is_valid 벡터에도 추가
                max_heap.push(ci(n, idx));  //최대 힙에 추가
                min_heap.push(ci(n, idx));  //최소 힙에 추가
                is_valid.push_back(true);  //true추가
                idx++;  //인덱스+1
                break;  //switch문 나오기
            case 'D': //n에 따라 최대 힙 또는 최소 힙에서 데이터 삭제
                if (n == 1) {  //1이면
                    deleteMax(max_heap); //D연산 전처리
                    if (!max_heap.empty()) { //D연산
                        is_valid[max_heap.top().second] = false;  //삭제할거니까 false로 바꿔주기
                        max_heap.pop();  //최댓값 삭제
                    }
                }
                if (n == -1) {  //-1이면
                    deleteMin(min_heap); //D연산 전처리
                    if (!min_heap.empty()) { //D연산
                        is_valid[min_heap.top().second] = false;  //삭제할거니까 false로 바꿔주기
                        min_heap.pop(); //최솟값 삭제
                    }
                }
                break;  //switch문 나오기
            }
        }
        //마지막으로 각 힙의 top이 valid 하도록 처리
        deleteMax(max_heap);  //valid할때까지 pop
        deleteMin(min_heap);  //valid할때까지 pop

        //출력
        if (max_heap.empty()) {  //heap이 비어있으면
            cout << "EMPTY\n";  //비어있다고 출력
        }
        else {
            cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';   //최대값과 최솟값 출력
        }
        is_valid.clear(); //새로운 테스트 케이스 전 is_valid 벡터 초기화
    }
}