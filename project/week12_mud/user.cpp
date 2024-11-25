#include "user.h"

// User 클래스의 구현
User::User(int startX, int startY, int startHP) : x(startX), y(startY), hp(startHP), itemCnt(0) {}

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

// 공격 함수 (기본 버전)
void User::doAttack() const {
    std::cout << "공격합니다!" << std::endl;
}

// Magician 클래스의 구현 (별도 구현 필요 없음, header에 inline 정의)

// Warrior 클래스의 구현 (별도 구현 필요 없음, header에 inline 정의)

