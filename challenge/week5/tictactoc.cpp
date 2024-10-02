#include <iostream>
using namespace std;

// 빙고를 체크하는 함수 추가
bool checkWin(char board[3][3], char currentUser) {
    // 가로와 세로 확인
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser)
            return true; // 가로 빙고
        if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser)
            return true; // 세로 빙고
    }
    // 대각선 확인
    if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser)
        return true; // 왼쪽 상단에서 오른쪽 하단 대각선
    if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser)
        return true; // 오른쪽 상단에서 왼쪽 하단 대각선

    return false;
}

// 모든 칸이 다 찼는지 확인하는 함수 추가
bool BoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false; // 빈칸이 있으면 아직 차지 않음
        }
    }
    return true; // 빈칸이 없으면 true
}

int main(){
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y;

    for (x = 0; x < numCell; x++){
        for (y = 0; y < numCell; y++){
            board[x][y] = ' ';
        }
    }

    int k = 0;
    char currentUser = 'X';
    while(true){
        switch (k % 2)
        {
        case 0:
            cout <<"첫번째 유저의 차례입니다 ->";
            currentUser = 'X';
            break;
        case 1:
            cout <<"두번째 유저의 차례입니다 -> ";
            currentUser = 'O';
            break;

        }

        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        if (x >= numCell || y >= numCell){
            cout << x << ", " << y << ": ";
            cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[x][y] != ' '){
            cout << x <<", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        board[x][y] = currentUser;

        // 빙고 체크 추가
        if (checkWin(board, currentUser)) {
            cout << "승리자: " << currentUser << endl;
            break; // 빙고 시 게임 종료
        }

        for (int i = 0; i < numCell; i++){
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++){
                cout << board[i][j];
                if (j == numCell - 1){
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

        // 모든 칸이 찼는지 확인하는 부분 추가
        if (BoardFull(board)) {
            cout << "모든 칸이 다 찼습니다. 무승부입니다!" << endl;
            break; // 모든 칸이 차면 게임 종료
        }

        k++;
    }

    return 0;//
}
