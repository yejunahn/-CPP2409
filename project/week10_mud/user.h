#ifndef USER_H
#define USER_H

class User {
private:
    int x;   // 유저의 현재 위치 x
    int y;   // 유저의 현재 위치 y
    int hp;  // 유저의 체력

public:
    // 생성자
    User(int startX = 0, int startY = 0, int startHP = 20);

    // 현재 위치 반환
    int getX() const;
    int getY() const;

    // 위치 설정
    void setX(int newX);
    void setY(int newY);

    // 체력 관련 함수
    void decreaseHP(int amount);
    void increaseHP(int amount);
    int getHP() const;

    // 체력 체크 함수
    bool isAlive() const;
};

#endif
