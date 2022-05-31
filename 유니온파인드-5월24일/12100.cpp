#include <iostream> //입출력 사용
#include <vector> //vector 사용
#include <algorithm>  //reverse()사용

using namespace std; //std namespace 사용중
typedef vector<vector<int>> matrix; //행렬

int n, ans = 0; //정수형 변수

int getMaxBlock(matrix& board) { //제일 큰 블록 찾는 함수
    int max_block = 0; //0으로 초기화
    for (int i = 0; i < n; i++) { //행
        for (int j = 0; j < n; j++) { //열
            max_block = max(max_block, board[i][j]); //제일 큰 블록 찾기
        }
    }
    return max_block; //블록 return
}

matrix transposeMatrix(matrix& board) { //전치행렬 구하는 함수
    matrix board_t(n, vector<int>(n, 0)); //새로운 행렬
    for (int i = 0; i < n; i++) { //행
        for (int j = 0; j < n; j++) { //열
            board_t[i][j] = board[j][i]; //i와 j순서 바꾸어서 새로운 행렬에 넣기
        }
    }
    return board_t; //전치행렬 return
}

/**
 * 상으로 이동하는 함수
 * - 한 열씩 검사하면서 위의 행부터 2개씩 같은 거 있다면 합치기
 * - 이때 블록 없는 부분은 넘어가고, 블록이 존재했던 값을 저장해서 비교하는 것이 중요!
 */
matrix upMove(matrix board) { //위로 움직이는 함수
    matrix temp(n, vector<int>(n, 0)); //새롭게 블록 저장할 배열
    for (int j = 0; j < n; j++) { //n번
        int idx = 0; //0으로 초기화
        int prev = 0; //0으로 초기화 
        for (int i = 0; i < n; i++) { //n번
            if (!board[i][j]) { //0일때
                continue; //다음 for문으로
            }
            if (board[i][j] == prev) { //prev와 같으면
                temp[idx - 1][j] *= 2; //2배 증가
                prev = 0; //0으로 초기화
            }
            else {
                temp[idx++][j] = board[i][j]; //일단 board[i][j]값 넣기
                prev = board[i][j]; //값 받아놓기
            }
        }
    }
    return temp; //위로 움직인 행렬 return
}

void backtracking(int cnt, matrix board) { //백트래킹 탐색
    if (cnt == 5) { //5번 했으면
        ans = max(ans, getMaxBlock(board)); //최대블록값 찾아서
        return; //return 하기
    }
    //Transpose matrix 구하기 (상->좌)
    matrix board_t = transposeMatrix(board); //전치행렬 받아오기
    //상
    backtracking(cnt + 1, upMove(board)); //카운트 수 올리고 upMove실행
    //하
    reverse(board.begin(), board.end()); //위아래 뒤집기
    backtracking(cnt + 1, upMove(board)); //카운트 수 올리고 upMove실행
    //좌
    backtracking(cnt + 1, upMove(board_t)); //카운트 수 올리고 전치행렬의 upMove실행
    //우
    reverse(board_t.begin(), board_t.end()); //전치행렬 위아래 뒤집기
    backtracking(cnt + 1, upMove(board_t)); //카운트 수 올리고 전치행렬의 upMove실행
}

/**
 * [2048 (Easy)]
 *
 * - 상, 하, 좌, 우로 이동하는 경우에 대해 최대 5번 이동시키는 모든 경우를 구한 후, 가장 큰 블록 찾는 문제 - 백트래킹
 * - 움직이는 함수는 하나만 짜고, 보드를 돌려가면서 상, 하, 좌, 우 모든 방향의 움직임을 만듦
 *
 * - 상 <-> 하: 행 순서를 뒤집어서 해결
 * - 상/하 <-> 좌/우: Transpose Matrix 활용
 *
 * - ex. 2 2 1 를 상, 하, 좌, 우로 이동하는 경우 구하는 법
 *       2 2 2
 *       4 4 4
 *  -상: 원래 배열에서 상으로 움직이는 함수 실행
 *       2 2 1    4 4 1
 *       2 2 2 -> 4 4 2
 *       4 4 4    0 0 4
 *  -하: 원래 배열의 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    4 4 4    4 4 4
 *       2 2 2 -> 2 2 2 -> 4 4 2
 *       4 4 4    2 2 1    0 0 1
 *  -좌: 원래 배열의 전치 행렬을 구한 후, 상으로 움직이는 함수 실행
 *       2 2 1    2 2 4    4 4 8
 *       2 2 2 -> 2 2 4 -> 1 2 4
 *       4 4 4    1 2 4    0 0 0
 *  -우: 원래 배열의 전치 행렬에서 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    1 2 4    1 4 8
 *       2 2 2 -> 2 2 4 -> 4 2 4
 *       4 4 4    2 2 4    0 0 0
 */

int main() { //main 함수
    //입력
    cin >> n; //사이즈 입력받기
    matrix board(n, vector<int>(n, 0)); //행렬 선언
    for (int i = 0; i < n; i++) { //n번 반복
        for (int j = 0; j < n; j++) { //n번 반복
            cin >> board[i][j]; //숫자 입력받기
        }
    }

    backtracking(0, board);//연산

    cout << ans; //출력
    return 0; //0을 return
}