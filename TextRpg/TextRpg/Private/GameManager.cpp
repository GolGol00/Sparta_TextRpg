#include "GameManager.h"
#include "PlayerCharacter.h"
#include <iostream>
#include <string>
using namespace std;

GameManager::GameManager() : bossCleared(false) {}

void GameManager::startGame() 
{
    cout << "게임을 시작합니다. " << endl;
    createCharacter();
    while (true) 
    {
        generateMonster();
        battle();

        if (bossCleared) 
        {
            showEnding();
            break;
        }

        cout << "상점을 방문하시겠습니까? (Y/N): ";
        char choice;
        cin >> choice;

        if (choice == 'Y' || choice == 'y') 
        {
            visitShop();
        }
        else if (choice == 'N' || choice == 'n')
        {
            battle();
        }

        if (PlayerCharacter::GetInstance()->getLevel() >= 10) 
        {
            cout << "레벨 10에 도달했습니다! 보스와의 전투를 시작합니다." << endl;
            battle(); 
            break;
        }
    }
}

void GameManager::createCharacter() 
{
    string playerName;

    cout << "플레이어 캐릭터의 이름을 입력하세요: ";
    getline(cin, playerName); // 캐릭터 이름 입력 받기

    try 
    {
        PlayerCharacter* player = PlayerCharacter::GetInstance(playerName);
        cout << "플레이어 캐릭터가 생성되었습니다: " << player->getName() << endl;
    }
    catch (const std::exception& e) 
    {
        cout << "문제가 발생했습니다: " << e.what() << endl;
    }
}

void GameManager::generateMonster() 
{
    cout << "몬스터가 생성되었습니다!" << endl;
}

void GameManager::battle() 
{
    cout << "전투가 시작됩니다!" << endl;

    // 전투가 끝난 후, 플레이어의 레벨 증가 또는 보스 클리어 여부 확인
    PlayerCharacter* player = PlayerCharacter::GetInstance();
    player->increaseLevel(1); // 예시로 레벨 증가

    if (player->getLevel() >= 10) 
    {
        bossCleared = true; // 보스 전투 가능
    }
}

void GameManager::displayInventory() 
{
    cout << "인벤토리 목록" << endl;
    // 인벤토리 출력 로직
}

void GameManager::visitShop() 
{
    cout << "상점에 방문하셨습니다!" << endl;
    // 상점 방문 로직 (아이템 구매 등)
}

void GameManager::showEnding() 
{
    cout << "축하합니다! 게임 엔딩을 보셨습니다!" << endl;
    cout << "엔딩 크레딧:" << endl;
    // 엔딩 크레딧 출력
    cout << "게임을 플레이 해주셔서 감사합니다!" << endl;
}
