#include <iostream>
using namespace std;

const int numCell = 3; // 보드판의 가로 세로 길이

// 좌표 유효성을 검사하는 함수
bool isValid(int x, int y, char board[numCell][numCell]) {
    if (x < 0 || x >= numCell || y < 0 || y >= numCell) { // 범위 벗어난 경우
        cout << x << ", " << y << ": 좌표가 보드판을 벗어났습니다." << endl;
        return false;
    }
    if (board[x][y] != ' ') { // 이미 돌이 있는 경우
        cout << x << ", " << y << ": 해당 위치에 이미 돌이 있습니다." << endl;
        return false;
    }
    return true;
}

// 승리 조건을 체크하는 함수
bool checkWin(char currentUser, char board[numCell][numCell]) {
    // 6.1. 가로 및 세로 승리 체크
    for (int i = 0; i < numCell; i++) {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser) rowWin = false;
            if (board[j][i] != currentUser) colWin = false;
        }
        if (rowWin || colWin) return true;
    }

    // 6.2. 대각선 승리 체크
    bool diagWin1 = true, diagWin2 = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][i] != currentUser) diagWin1 = false;
        if (board[i][numCell - i - 1] != currentUser) diagWin2 = false;
    }
    return diagWin1 || diagWin2;
}

int main() {
    int k = 0; // 차례를 체크하는 변수
    char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
    char players[3] = {'X', 'O', 'H'}; // 3인 게임을 위한 플레이어

    // 보드판 초기화
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            board[i][j] = ' ';
        }
    }

    // 게임을 무한 반복
    while (true) {
        char currentUser = players[k % 3];
        cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 차례입니다. -> ";

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        int x, y;
        cin >> x >> y;

        // 좌표의 유효성 체크
        if (!isValid(x, y, board)) continue;

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드판 출력
        for (int i = 0; i < numCell; i++) {
            cout << "---|";
            for (int j = 0; j < numCell; j++) {
                cout << " " << board[i][j] << " ";
                if (j < numCell - 1) cout << "|";
            }
            cout << " |" << endl;
        }
        cout << "---|---|---|" << endl;

        // 승리 조건 체크
        if (checkWin(currentUser, board)) {
            cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            break;
        }

        // 7. 모든 칸이 다 찼는지 체크
        int filledCells = 0;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] != ' ') filledCells++;
            }
        }
        if (filledCells == numCell * numCell) {
            cout << "모든 칸이 다 찼습니다. 게임을 종료합니다." << endl;
            break;
        }

        k++; // 다음 차례로 이동
    }

    return 0;
}
