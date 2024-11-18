#ifndef USER_H
#define USER_H

#include <iostream>

class User {
private:
    int x;       // 유저의 현재 위치 x
    int y;       // 유저의 현재 위치 y
    int hp;      // 유저의 체력
    int itemCnt; // 아이템 먹은 횟수

public:
    // 생성자
    User(int startX = 0, int startY = 0, int startHP = 20) 
        : x(startX), y(startY), hp(startHP), itemCnt(0) {}

    // 현재 위치 반환
    int getX() const { return x; }
    int getY() const { return y; }

    // 위치 설정
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    // 체력 관련 함수
    void decreaseHP(int amount) { hp -= amount; }
    void increaseHP(int amount) { hp += amount; }
    int getHP() const { return hp; }

    // 체력 체크 함수
    bool isAlive() const { return hp > 0; }

    // 아이템 먹은 횟수 관련 함수
    void eatItem() { itemCnt++; }
    int getItemCount() const { return itemCnt; }

    // 출력 연산자 중복 정의
    friend std::ostream& operator<<(std::ostream& os, const User& user) {
        os << "현재 HP는 " << user.getHP() << " 이고, 먹은 아이템은 총 " << user.getItemCount() << "개 입니다.";
        return os;
    }
};

#endif

