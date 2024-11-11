#include "user.h"

// 생성자
User::User(int startX, int startY, int startHP) : x(startX), y(startY), hp(startHP) {}

// 현재 위치 반환
int User::getX() const { return x; }
int User::getY() const { return y; }

// 위치 설정
void User::setX(int newX) { x = newX; }
void User::setY(int newY) { y = newY; }

// 체력 감소 및 증가 함수
void User::decreaseHP(int amount) { hp -= amount; }
void User::increaseHP(int amount) { hp += amount; }
int User::getHP() const { return hp; }

// 체력 체크 함수
bool User::isAlive() const { return hp > 0; }
