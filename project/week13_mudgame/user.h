#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
public:
    virtual ~User() = default;

    // 순수 가상 함수
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual void setX(int newX) = 0;
    virtual void setY(int newY) = 0;
    virtual void decreaseHP(int amount) = 0;
    virtual void increaseHP(int amount) = 0;
    virtual int getHP() const = 0;
    virtual bool isAlive() const = 0;
    virtual void eatItem() = 0;
    virtual void doAttack() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

class Magician : public User {
private:
    int x, y, hp, itemCnt;

public:
    Magician(int startX = 0, int startY = 0, int startHP = 20);

    int getX() const override;
    int getY() const override;
    void setX(int newX) override;
    void setY(int newY) override;
    void decreaseHP(int amount) override;
    void increaseHP(int amount) override;
    int getHP() const override;
    bool isAlive() const override;
    void eatItem() override;
    void doAttack() const override;
};

class Warrior : public User {
private:
    int x, y, hp, itemCnt;

public:
    Warrior(int startX = 0, int startY = 0, int startHP = 20);

    int getX() const override;
    int getY() const override;
    void setX(int newX) override;
    void setY(int newY) override;
    void decreaseHP(int amount) override;
    void increaseHP(int amount) override;
    int getHP() const override;
    bool isAlive() const override;
    void eatItem() override;
    void doAttack() const override;
};

#endif

