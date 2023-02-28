#include <iostream>  //입출력 사용
#include <vector>   //vector 사용
#include <queue>  //queue 사용
#include <algorithm>  //sort 사용

using namespace std;  //std namespace 사용중
const int INF = 401;  //최댓값 고정으로 선언
typedef pair<int, int> ci;  //pair형 ci로 선언

pair<int, ci> nextPos(int n, int shark_size, ci& shark, vector<vector<int>>& board) {  //이동할 곳까지의 거리와 좌표 반환하는 함수
    int dr[4] = { -1, 1, 0, 0 }; //왼,오,아래,위
    int dc[4] = { 0, 0, -1, 1 };  //왼,오,아래,위

    int min_dist = INF; //INF로 초기화
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> dist(n, vector<int>(n, 0)); //상어의 방문 여부 + 거리
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    dist[shark.first][shark.second] = 1;  //초기 상어 위치 방문 처리해줌
    q.push(shark); //좌표 push
    while (!q.empty()) {  //q가 비어있지않으면
        int row = q.front().first;  //x좌표
        int col = q.front().second;  //y좌표
        q.pop();  //삭제

        if (dist[row][col] >= min_dist) { //최단거리 이상은 탐색할 필요 없음
            continue; //다음 while문으로 넘어가
        }
        for (int i = 0; i < 4; i++) {  //4번 반복
            int nr = row + dr[i];  //새로운 x좌표
            int nc = col + dc[i];  //새로운 y좌표
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || dist[nr][nc] || board[nr][nc] > shark_size) {  //확인하지 않아도 되는 부분
                continue;  //다음 for문
            }

            dist[nr][nc] = dist[row][col] + 1; //거리
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc);  //물고기 위치 push
                min_dist = dist[nr][nc]; //최소 거리로 갱신
                continue; //다음 for문
            }
            q.push({ nr, nc });  //상어 위치 push
        }
    }

    if (list.empty()) { //상어가 갈 수 있는 곳이 없음
        return { min_dist, {-1, -1} }; //갈 수 없음을 의미하는 값 return
    }

    sort(list.begin(), list.end(), [](const ci& p1, const ci& p2) { //정렬 (compare 함수를 정의하지 않아도 됨)
        if (p1.first != p2.first) {  //x값 다를 때
            return p1.first < p2.first; //x값 오름차순
        }
        return p1.second < p2.second;  //y값 오름차순
        });
    return { min_dist - 1, list[0] }; //거리와 젤 가까운곳 좌표 return
}

int simulation(int n, pair<int, int>& shark, vector<vector<int>>& board) {  //초 반환하는 함수
    int ans = 0, size = 2, cnt = 0;  //정수형 변수들 초기화
    while (true) {  //break될때까지 무한히 반복
        pair<int, ci> result = nextPos(n, size, shark, board);  //다음 상어 위치
        if (result.first == INF) { //더 이상 먹을 수 있는 물고기가 공간에 없음
            break;  //break
        }
        ans += result.first;  //거리(초)더하기
        cnt++;  //카운트 +1
        if (cnt == size) { //상어 크기 증가
            cnt = 0;  //카운트 다시 0으로 초기화
            size++;  //상어 크기 1증가
        }

        //상어 이동
        board[shark.first][shark.second] = 0; //0으로 초기화
        shark = result.second;  //다음 위치로 이동
    }
    return ans;  //초 반환
}

/**
 * [아기 상어]
 *
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */

int main() {  //main 함수
    int n; //정수형 변수
    pair<int, int> shark_pos;  //int,int형 pair선언

    cin >> n;  //입력받기
    vector<vector<int>> board(n, vector<int>(n));  //n*n 행렬
    for (int i = 0; i < n; i++) {  //n번 반복
        for (int j = 0; j < n; j++) {  //n번 반복
            cin >> board[i][j];  //입력받기
            if (board[i][j] == 9) { //상어의 초기 위치
                shark_pos = make_pair(i, j);   //상어 위치 pair로 묶어 저장
            }
        }
    }

    cout << simulation(n, shark_pos, board);  //함수 결과 출력
    return 0;  //0을 return
}