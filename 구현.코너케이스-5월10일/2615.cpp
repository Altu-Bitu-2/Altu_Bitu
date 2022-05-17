#include <iostream>  //입출력 사용
#include <vector> //vector 사용

using namespace std;  //std namespace 사용중
const int SIZE = 19;  //size 19로 고정

bool promising(int r, int c, int stone, vector<vector<int>>& board) { //범위와 돌의 종류가 유효한지 확인
    return r >= 0 && r < SIZE&& c >= 0 && c < SIZE&& board[r][c] == stone; //하나라도 위배되면 0
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>>& board) { //이긴돌 있는지 확인
    int dr[4] = { 0, 1, 1, -1 }; //가로, 세로, 우하향 대각선, 우상향 대각선
    int dc[4] = { 1, 0, 1, 1 }; //가로, 세로, 우하향 대각선, 우상향 대각선

    if (promising(r - dr[d], c - dc[d], stone, board)) { //(r, c) 이전에 위치한 이어지는 돌이 있나?
        return false; //false를 return
    }
    int cnt = 0;  //0으로 초기화
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++;  //cnt+1
        r += dr[d]; //행
        c += dc[d]; //열
    }
    return cnt == 5;  //5면 true
}

bool isEnd(int r, int c, vector<vector<int>>& board) {  //이긴 돌 있는지를 bool형으로 return하는 함수
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) { //이긴 돌 있으면 
            return true;  //true return
        }
    }
    return false; //false return
}

/**
 * [오목]
 *
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. (주의) 육목이상이 되는지 확인해야 함
 *
 */

int main() {  //main 함수
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));  //19*19 행렬

    for (int i = 0; i < SIZE; i++) {  //반복
        for (int j = 0; j < SIZE; j++) {  //반복
            cin >> board[i][j]; //입력받기
        }
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) { //반복
        for (int j = 0; j < SIZE; j++) { //반복
            if (!board[i][j]) { //돌이 없음
                continue; //다음 for문
            }
            if (isEnd(i, j, board)) { //누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1; //이긴 돌 종류와 위치 출력
                return 0; //0을 return
            }
        }
    }
    cout << 0; //0을 출력
    return 0; //0을 return
}