#include <iostream> //입출력 사용
#include <vector> //vector 사용

using namespace std; //std namespace 사용중

int cntCleanRobot(int r, int c, int d, vector<vector<int>>& board) { //청소 개수 return하는 함수
    int dr[4] = { -1, 0, 1, 0 }; //상, 우, 하, 좌
    int dc[4] = { 0, 1, 0, -1 }; //상, 우, 하, 좌

    int step = 0, ans = 0; //0으로 초기화
    while (true) { //일단 반복
        if (board[r][c] == 0) { //빈칸이면 청소
            board[r][c] = 2; //청소했다는 뜻
            ans++; //청소 개수+1
        }

        if (step == 4) { //4번 했고
            if (board[r - dr[d]][c - dc[d]] == 1) { //벽이면
                return ans;  //작동 종료
            }
            r -= dr[d]; //한칸 후진
            c -= dc[d]; //한칸 후진
            step = 0; //0으로 초기화
        }
        else { //아직 4번 아니면
            d = (d + 3) % 4; //모듈러 연산
            if (board[r + dr[d]][c + dc[d]]) { //빈 공간이 아니면
                step++; //2-a 회수+1
                continue; //계속 진행
            }
            r += dr[d]; //왼쪽 전진
            c += dc[d]; //왼쪽 전진
            step = 0; //0으로 초기화
        }
    }
}

/**
 * [로봇 청소기]
 *
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() { //main함수
    int n, m, r, c, d; //정수형 변수들

    cin >> n >> m >> r >> c >> d; //입력
    vector<vector<int>> board(n, vector<int>(m, 0)); //n*m행렬
    for (int i = 0; i < n; i++) { //n번 반복
        for (int j = 0; j < m; j++) { //m번 반복
            cin >> board[i][j]; //입력받기
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board); //결과 출력
    return 0; //0을 return
}