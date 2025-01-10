#include "GameManager.h"
#include "PlayerCharacter.h"
#include <iostream>
#include <string>
using namespace std;

GameManager::GameManager() : bossCleared(false) {}

void GameManager::startGame() 
{
    cout << "������ �����մϴ�. " << endl;
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

        cout << "������ �湮�Ͻðڽ��ϱ�? (Y/N): ";
        char choice;
        cin >> choice;

        if (choice == 'Y' || choice == 'y') 
        {
            visitShop();
        }
        else if (choice == 'N' || choice == 'n')
        {
            // ��� ������ ����
        }

        // ���� �� ���� 10 ���� ���� Ȯ��
        if (PlayerCharacter::GetInstance()->getLevel() >= 10) 
        {
            cout << "���� 10�� �����߽��ϴ�! �������� ������ �����մϴ�." << endl;
            battle(); // ���� ����
            break;
        }
    }
}

void GameManager::createCharacter() 
{
    string playerName;

    cout << "�÷��̾� ĳ������ �̸��� �Է��ϼ���: ";
    getline(cin, playerName); // ĳ���� �̸� �Է� �ޱ�

    try 
    {
        PlayerCharacter* player = PlayerCharacter::GetInstance(playerName);
        cout << "�÷��̾� ĳ���Ͱ� �����Ǿ����ϴ�: " << player->getName() << endl;
    }
    catch (const std::exception& e) 
    {
        cout << "������ �߻��߽��ϴ�: " << e.what() << endl;
    }
}

void GameManager::generateMonster() 
{
    // ���� ���� ���� (��: �������� ���� ������ ����)
    cout << "���Ͱ� �����Ǿ����ϴ�!" << endl;
}

void GameManager::battle() 
{
    // ���� ���� (������ ���� ����)
    cout << "������ ���۵˴ϴ�!" << endl;

    // ������ ���� ��, �÷��̾��� ���� ���� �Ǵ� ���� Ŭ���� ���� Ȯ��
    PlayerCharacter* player = PlayerCharacter::GetInstance();
    player->increaseLevel(1); // ���÷� ���� ����

    if (player->getLevel() >= 10) 
    {
        bossCleared = true; // ���� ���� ����
    }
}

void GameManager::displayInventory() 
{
    cout << "�κ��丮 ���" << endl;
    // �κ��丮 ��� ����
}

void GameManager::visitShop() 
{
    cout << "������ �湮�ϼ̽��ϴ�!" << endl;
    // ���� �湮 ���� (������ ���� ��)
}

void GameManager::showEnding() 
{
    cout << "�����մϴ�! ���� ������ ���̽��ϴ�!" << endl;
    cout << "���� ũ����:" << endl;
    // ���� ũ���� ���
    cout << "������ �÷��� ���ּż� �����մϴ�!" << endl;
}
