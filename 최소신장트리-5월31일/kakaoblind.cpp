#include <vector> //vector 사용
#include <iostream> //입출력 사용

using namespace std; //std namespace 사용중

vector<vector<vector<bool>>> board;  //구조물 배치 나타낼 행렬

bool validate(int x, int y, int p, int n) { //현재 상태가 조건에 만족하는지 (x, y) 중심으로 확인
    if (p == 0) { //기둥
        if (y == 0) { //바닥 위
            return true; //만족
        }
        if (board[x][y][1] || (x > 0 && board[x - 1][y][1])) { //보의 왼쪽/오른쪽 끝
            return true; //만족
        }
        if (y > 0 && board[x][y - 1][0]) { //기둥 위
            return true; //만족
        }
    }
    else { //보
        if (y > 0 && board[x][y - 1][0]) { //왼쪽 끝이 기둥 위
            return true; //만족
        }
        if (x < n && y > 0 && board[x + 1][y - 1][0]) { //오른쪽 끝이 기둥 위
            return true;//만족
        }
        if (x > 0 && x < n && board[x - 1][y][1] && board[x + 1][y][1]) { //양쪽 끝이 보와 연결
            return true;//만족
        }
    }
    return false; //모두 해당 안될 경우 false
}

bool checkRemovable(int x, int y, int n) { //(x, y)에 있는 구조물을 삭제할 수 있는지 확인
    int dx[3] = { -1, 0, 1 }; //왼,가운데,오
    int dy[3] = { -1, 0, 1 }; //아래,가운데,위
    //기둥이 삭제된 경우, 해당 기둥 위에 보가 있었을 수 있으므로 (조건 2-b) 대각선도 확인이 필요
    for (int i = 0; i < 3; i++) { //3번 반복
        for (int j = 0; j < 3; j++) { //3번 반복
            int nx = x + dx[i]; //x좌표
            int ny = y + dy[j]; //y좌표
            if (nx < 0 || nx > n || ny < 0 || ny > n) { //좌표 벗어나면
                continue; //다음 for문
            }
            for (int k = 0; k < 2; k++) { //기둥과 보
                if (board[nx][ny][k] && !validate(nx, ny, k, n)) { //board값이 true이고 조건 만족하지 않으면
                    return false; //false를 return
                }
            }
        }
    }
    return true; //true를 return
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) { //결과 행렬 return
    vector<vector<int>> answer; //결과행렬
    board.assign(n + 1, vector<vector<bool>>(n + 1, vector<bool>(2, false))); //현재 설치 현황
    //시뮬레이션
    for (int i = 0; i < build_frame.size(); i++) { //frame 수 만큼 반복
        int x = build_frame[i][0]; //x좌표
        int y = build_frame[i][1]; //y좌표
        int p = build_frame[i][2]; //기둥인지 보인지
        int cmd = build_frame[i][3]; //삭제인지 설치인지
        if (!cmd) { //삭제
            board[x][y][p] = false; //board에 false표시
            if (!checkRemovable(x, y, n)) { //삭제할 수 없으면
                board[x][y][p] = true; //board에 true표시
            }
        }
        else if (validate(x, y, p, n)) { //설치 가능한 경우
            board[x][y][p] = true; //board에 true표시
        }
    }
    //결과
    for (int i = 0; i <= n; i++) { //반복
        for (int j = 0; j <= n; j++) { //반복
            for (int k = 0; k < 2; k++) { //기둥인지 보인지
                if (board[i][j][k]) { //true이면
                    answer.push_back({ i, j, k }); //결과 배열에 push
                }
            }
        }
    }
    return answer; //결과 return
}

/**
 * [기둥과 보 설치]
 * 들어오는 입력에 대해 설치 또는 삭제 이후에도 기본 조건에 만족하는지 확인
 *
 * [기본 조건]
 * 1. 기둥
 *     a. 바닥 위
 *     b. 보의 한 쪽 끝
 *     c. 다른 기둥 위
 * 2. 보
 *     a. 한쪽 끝이 기둥 위
 *     b. 양쪽 끝이 보와 연결
 *
 * - 설치: 설치하려는 좌표가 조건을 만족하는지 확인
 * - 삭제: 해당 기둥/보를 삭제했을 시 영향을 받는 인접한 기둥/보가 여전히 조건을 만족하고 있는지 확인
 */
int main() { //main 함수
    int n = 5; //벽면 사이즈
    vector<vector<int>> build_frame = { {1, 0, 0, 1}, //구조물 배치
                                       {1, 1, 1, 1}, //구조물 배치
                                       {2, 1, 0, 1}, //구조물 배치
                                       {2, 2, 1, 1}, //구조물 배치
                                       {5, 0, 0, 1}, //구조물 배치
                                       {5, 1, 0, 1}, //구조물 배치
                                       {4, 2, 1, 1}, //구조물 배치
                                       {3, 2, 1, 1} }; //구조물 배치
    vector<vector<int>> ans = solution(n, build_frame); //결과 배열
    for (int i = 0; i < ans.size(); i++) {  //행
        for (int j = 0; j < ans[0].size(); j++) { //열
            cout << ans[i][j] << ' ';  //결과 출력
        }
        cout << '\n'; //줄바꿈
    }
    return 0; //0을 return
}