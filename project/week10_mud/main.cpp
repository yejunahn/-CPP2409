#include <iostream>
#include <vector>
#include <string>
#include "user.h"  // User 클래스가 정의된 헤더 파일
using namespace std;

const int mapX = 5;
const int mapY = 5;
const int INITIAL_HP = 20;

// 함수 선언
bool checkXY(int user_x, int user_y);
void displayMap(const vector<vector<int>>& map, int user_x, int user_y);
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

    // User 객체 생성
    User player(0, 0, INITIAL_HP);

    while (true) {
        // 체력 체크
        if (!CheckUser(player)) {
            cout << "체력이 0이 되어 실패했습니다. 게임을 종료합니다." << endl;
            break;
        }

        displayMap(map, player.getX(), player.getY());
        cout << "현재 체력: " << player.getHP() << endl;

        // 명령 입력
        string user_input;
        cout << "명령어를 입력하세요 (상, 하, 좌, 우, 지도, 종료): ";
        cin >> user_input;

        // 기존 위치 초기화
        map[player.getY()][player.getX()] = 0;

        // 입력 명령어 처리
        if (user_input == "상") {
            player.setY(player.getY() - 1);
        } else if (user_input == "하") {
            player.setY(player.getY() + 1);
        } else if (user_input == "좌") {
            player.setX(player.getX() - 1);
        } else if (user_input == "우") {
            player.setX(player.getX() + 1);
        } else if (user_input == "지도") {
            displayMap(map, player.getX(), player.getY());
            continue;
        } else if (user_input == "종료") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
            map[player.getY()][player.getX()] = 5;
            continue;
        }

        // 지도 밖으로 나가려 할 때 원래 위치로 되돌리기
        if (!checkXY(player.getX(), player.getY())) {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
            if (user_input == "상") player.setY(player.getY() + 1);
            else if (user_input == "하") player.setY(player.getY() - 1);
            else if (user_input == "좌") player.setX(player.getX() + 1);
            else if (user_input == "우") player.setX(player.getX() - 1);
            map[player.getY()][player.getX()] = 5;
            continue;
        }

        // 이동 후 체력 감소
        player.decreaseHP(1);

        // 위치 상호작용 및 이벤트
        interactWithPosition(map, player);

        // 목적지 체크
        if (checkGoal(map, player.getX(), player.getY())) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            break;
        }

        // 새로운 위치에 플레이어 위치 업데이트
        map[player.getY()][player.getX()] = 5;
    }
    return 0;
}

// 사용자 위치와 이벤트를 출력하는 함수
void displayMap(const vector<vector<int>>& map, int user_x, int user_y) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
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

// 지도 밖으로 나가지 않도록 위치 체크하는 함수
bool checkXY(int user_x, int user_y) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

// 현재 위치에 상호작용 요소가 있는지 확인하고 이벤트 처리
void interactWithPosition(vector<vector<int>>& map, User& user) {
    switch (map[user.getY()][user.getX()]) {
        case 1:
            cout << "아이템을 발견했습니다!" << endl;
            break;
        case 2:
            cout << "적을 만났습니다! 체력이 2 감소합니다." << endl;
            user.decreaseHP(2);
            break;
        case 3:
            cout << "포션을 발견하여 체력을 5 회복합니다!" << endl;
            user.increaseHP(5);
            map[user.getY()][user.getX()] = 0; // 포션은 일회성이므로 발견 후 빈 공간으로 바꿈
            break;
    }
}

// 유저가 목표 지점에 도달했는지 체크하는 함수
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}

// 유저의 체력이 0인지 체크하는 함수
bool CheckUser(const User& user) {
    return user.isAlive();
}
