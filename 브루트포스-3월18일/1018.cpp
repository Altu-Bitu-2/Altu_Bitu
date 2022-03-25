#include <iostream>  //입출력 함수 사용
#include <vector>   //vector사용

using namespace std;  //std namespace 사용중

const int SIZE = 64; //체스판 칸 개수

//(x, y)에서 시작하는 8*8 체스판을 만드는데 필요한 최소 카운트 리턴
//검정으로 시작하는 체스판을 기준으로 계산(b_count) -> 절반(32) 이상이면 흰색으로 시작하는 체스판 카운트(64 - b_count) 리턴
int chessChange(int row, int col, vector<vector<char>>& board) {   //바꿔야하는 최소 개수를 return해주는 함수
    int b_cnt = 0; //B로 시작하는 체스판 만들기 위한 카운트

    for (int i = 0; i < 8; i++) { //행 변화값
        for (int j = 0; j < 8; j++) { //열 변화값
            if ((i + j) % 2 == 0 && board[row + i][col + j] != 'B') {     //B로 시작한다고 가정하고 있으니까 (i + j) % 2 == 0이면서 문자가 B인지 확인
                b_cnt++;  //b_cnt+1
            }
            else if ((i + j) % 2 && board[row + i][col + j] != 'W') {     //(i + j) % 2가 1이고 문자가 W인지 확인
                b_cnt++;  //b_cnt+1
            }

        }
    }

    //최솟값 리턴
    if (b_cnt > SIZE / 2) {    //b_cnt가 32보다 크게 나오면 W로 시작하는 체스판에서의 최소개수가 더 적을 것
        return SIZE - b_cnt;   //W로 시작할때는 정반대이니까 64에서 b_cnt를 빼주기만 해도 된다
    }
    return b_cnt;  //b_cnt를 return
}

/**
 * [체스판 다시 칠하기]
 * - 나올 수 있는 체스판의 경우: 2가지
 * - (0, 0)이 검정인 경우, 흰색인 경우
 * - 검정으로 시작하는 체스판의 경우, 인덱스 i+j가 짝수일 때 'B'임을 이용
 *
 * 1.  (0, 0) 인덱스부터 차례로 8*8 체스판 만들 때 바꿔야 하는 칸 수를 계산하고, 그 중 최솟값 구하기
 *
 * 보드 크기 <= 2,500
 * 한 위치에 대한 체스판 비교 연산 = 64번
 * 총 연산 수 = 2,500 * 64 < 1억 -> 브루트 포스 가능
 */

int main() {
    int n, m;    //int형 변수 n,m선언
    int ans = SIZE + 1; //정답은 체스판 칸 개수 + 1 로 초기화

    //입력
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m)); //행: n, 열: m
    for (int i = 0; i < n; i++) { //보드 입력(행)
        for (int j = 0; j < m; j++) { //보드 입력(열)
            cin >> board[i][j];   //값 입력받기
        }
    }

    //연산
    for (int i = 0; i <= n - 8; i++) {    //보드 크기가 8*8이니까 n-8까지만
        for (int j = 0; j <= m - 8; j++) {    //보드 크기가 8*8이니까 m-8까지만
            int cnt = chessChange(i, j, board); //시작인덱스가 (i,j)인 체스판 만드는 최솟값
            ans = min(ans, cnt); //최솟값 갱신
        }
    }

    //출력
    cout << ans << '\n';   //최소값 출력
    return 0;   //0을 return
}