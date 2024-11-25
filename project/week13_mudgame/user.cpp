#include "user.h"

Magician::Magician(int startX, int startY, int startHP)
    : x(startX), y(startY), hp(startHP), itemCnt(0) {}

int Magician::getX() const { return x; }
int Magician::getY() const { return y; }
void Magician::setX(int newX) { x = newX; }
void Magician::setY(int newY) { y = newY; }
void Magician::decreaseHP(int amount) { hp -= amount; }
void Magician::increaseHP(int amount) { hp += amount; }
int Magician::getHP() const { return hp; }
bool Magician::isAlive() const { return hp > 0; }
void Magician::eatItem() { itemCnt++; }
void Magician::doAttack() const { std::cout << "마법 사용!" << std::endl; }

Warrior::Warrior(int startX, int startY, int startHP)
    : x(startX), y(startY), hp(startHP), itemCnt(0) {}

int Warrior::getX() const { return x; }
int Warrior::getY() const { return y; }
void Warrior::setX(int newX) { x = newX; }
void Warrior::setY(int newY) { y = newY; }
void Warrior::decreaseHP(int amount) { hp -= amount; }
void Warrior::increaseHP(int amount) { hp += amount; }
int Warrior::getHP() const { return hp; }
bool Warrior::isAlive() const { return hp > 0; }
void Warrior::eatItem() { itemCnt++; }
void Warrior::doAttack() const { std::cout << "베기 사용!" << std::endl; }

