#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>

class GameManager {
public:
    GameManager();
    void startGame();
    void createCharacter();
    void generateMonster();
    void battle();
    void displayInventory();
    void visitShop();
    void showEnding();

private:
    bool bossCleared;
};

#endif
