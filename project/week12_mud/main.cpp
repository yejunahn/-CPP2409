#include <iostream>
#include <vector>
#include <string>
#include "user.h"  // User, Magician, Warrior 클래스가 정의된 헤더 파일
using namespace std;

const int mapX = 5;
const int mapY = 5;
const int INITIAL_HP = 20;

// 함수 선언
bool checkXY(int user_x, int user_y);
void displayMap(const vector<vector<int>>& map, int user1_x, int user1_y, int user2_x, int user2_y);
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y);
void interactWithPosition(vector<vector<int>>& map, User& user);
bool CheckUser(const User& user);

int main() {
    // 2차원 벡터로 맵 선언
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    // Magician과 Warrior 객체 생성
    Magician player1(0, 0, INITIAL_HP);
    Warrior player2(4, 4, INITIAL_HP);

    int turn = 0; // 0: Magician, 1: Warrior
    while (true) {
        // 현재 플레이어 선택
        User& currentPlayer = (turn == 0) ? player1 : player2;
        cout << (turn == 0 ? "Magician의 턴" : "Warrior의 턴") << endl;

        // 체력 체크
        if (!CheckUser(currentPlayer)) {
            cout << (turn == 0 ? "Magician" : "Warrior") << "의 체력이 0이 되어 실패했습니다. 게임을 종료합니다." << endl;
            break;
        }

        // 현재 맵 출력
        displayMap(map, player1.getX(), player1.getY(), player2.getX(), player2.getY());
        cout << "현재 체력: " << currentPlayer.getHP() << endl;

        // 명령 입력
        string user_input;
        cout << "명령어를 입력하세요 (상, 하, 좌, 우, 지도, 종료, 정보, 스킬): ";
        cin >> user_input;

        // 기존 위치 초기화
        map[currentPlayer.getY()][currentPlayer.getX()] = 0;

        // 입력 명령어 처리
        if (user_input == "상") {
            currentPlayer.setY(currentPlayer.getY() - 1);
        } else if (user_input == "하") {
            currentPlayer.setY(currentPlayer.getY() + 1);
        } else if (user_input == "좌") {
            currentPlayer.setX(currentPlayer.getX() - 1);
        } else if (user_input == "우") {
            currentPlayer.setX(currentPlayer.getX() + 1);
        } else if (user_input == "지도") {
            displayMap(map, player1.getX(), player1.getY(), player2.getX(), player2.getY());
            continue;
        } else if (user_input == "종료") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else if (user_input == "정보") {
            cout << currentPlayer << endl;
            map[currentPlayer.getY()][currentPlayer.getX()] = 5;  // 현재 위치 표시
            continue;
        } else if (user_input == "스킬") {
            currentPlayer.useSkill();
            map[currentPlayer.getY()][currentPlayer.getX()] = 5; // 현재 위치 표시
            continue;
        } else {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
            map[currentPlayer.getY()][currentPlayer.getX()] = 5;
            continue;
        }

        // 지도 밖으로 나가려 할 때 원래 위치로 되돌리기
        if (!checkXY(currentPlayer.getX(), currentPlayer.getY())) {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
            if (user_input == "상") currentPlayer.setY(currentPlayer.getY() + 1);
            else if (user_input == "하") currentPlayer.setY(currentPlayer.getY() - 1);
            else if (user_input == "좌") currentPlayer.setX(currentPlayer.getX() + 1);
            else if (user_input == "우") currentPlayer.setX(currentPlayer.getX() - 1);
            map[currentPlayer.getY()][currentPlayer.getX()] = 5;
            continue;
        }

        // 이동 후 체력 감소
        currentPlayer.decreaseHP(1);

        // 위치 상호작용 및 이벤트
        interactWithPosition(map, currentPlayer);

        // 목적지 체크
        if (checkGoal(map, currentPlayer.getX(), currentPlayer.getY())) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            break;
        }

        // 새로운 위치에 플레이어 위치 업데이트
        map[currentPlayer.getY()][currentPlayer.getX()] = 5;

        // 턴 교체
        turn = 1 - turn;
    }
    return 0;
}

// 지도 출력 함수
void displayMap(const vector<vector<int>>& map, int user1_x, int user1_y, int user2_x, int user2_y) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (i == user1_y && j == user1_x) {
                cout << " MAG  |";
            } else if (i == user2_y && j == user2_x) {
                cout << " WAR  |";
            } else {
                int posState = map[i][j];
                switch (posState) {
                    case 0: cout << "      |"; break;
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break;
                    case 3: cout << " 포션 |"; break;
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}
