#include "Framework.h"
#include <iostream>
#include <string>
using namespace std;

GameManager::GameManager() : bossCleared(false) {}

void GameManager::StartGame()
{
    cout << "������ �����մϴ�. " << endl;
    CreateCharacter();
    while (true)
    {
        GenerateMonster();
        Battle();

        if (bossCleared)
        {
            ShowEnding();
            break;
        }

        /*
        cout << "������ �湮�Ͻðڽ��ϱ�? (Y/N): ";
        char choice;
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            VisitShop();
        }
        else if (choice == 'N' || choice == 'n')
        {
            Battle();
        }

        */
        if (PlayerCharacter::GetInstance()->GetLevel() >= 10)
        {
            cout << "���� 10�� �����߽��ϴ�! �������� ������ �����մϴ�." << endl;
            Battle();
            break;
        }
    }
}

void GameManager::CreateCharacter()
{
    string playerName;

    cout << "�÷��̾� ĳ������ �̸��� �Է��ϼ���: ";
    getline(cin, playerName); // ĳ���� �̸� �Է� �ޱ�

    PlayerCharacter* player = PlayerCharacter::GetInstance(playerName);

}

void GameManager::GenerateMonster()
{
    cout << "���Ͱ� �����Ǿ����ϴ�!" << endl;
}

void GameManager::Battle()
{
    cout << "������ ���۵˴ϴ�!" << endl;

    // ������ ���� ��, �÷��̾��� ���� ���� �Ǵ� ���� Ŭ���� ���� Ȯ��
    PlayerCharacter* player = PlayerCharacter::GetInstance();


    if (player->GetLevel() >= 10)
    {
        bossCleared = true; // ���� ���� ����
    }
}

void GameManager::DisplayInventory()
{
    cout << "�κ��丮 ���" << endl;
    // �κ��丮 ��� ����
}

void GameManager::VisitShop()
{
    cout << "������ �湮�ϼ̽��ϴ�!" << endl;
    // ���� �湮 ���� (������ ���� ��)
}

void GameManager::ShowEnding()
{
    cout << "�����մϴ�! ���� ������ ���̽��ϴ�!" << endl;
    cout << "���� ũ����:" << endl;
    // ���� ũ���� ���
    cout << "������ �÷��� ���ּż� �����մϴ�!" << endl;
}