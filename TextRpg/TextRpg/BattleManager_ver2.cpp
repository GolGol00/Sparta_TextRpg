#include "BattleManager_ver2.h"


bool BattleManager::Battle() {
	//���� ���� Ȯ��
	if (_player == nullptr)
	{
		return false;
	}

	if (_currentMonster == nullptr)
	{
		_currentMonster = _eFactory->getMonster(1, 1);
	}

	//���� ������ ���� ����

	//���� HPȮ��
	if (_player->GetHealth() <= 0 || _currentMonster->GetHP() <= 0)
	{
		return false;
	}

	//���� ü�� ���� ������� �����ۻ��
	if (_player->GetHealth() <= _currentMonster->GetDamage())
	{
		_player->UseItem(0);
	}



	//1. �÷��̾� ���� 2. ���Ͱ���

	_currentMonster->TakeDamage(_player->GetAttack());

	//���� HPȮ�� // �̺κ� ���߿� TakeDamage() ���� ������ �޴� �Լ����� ��� ��ȯ��		
	if (_currentMonster->GetHP() <= 0)
	{
		//�׾����� ����
		_player->AddExperience(50);
		_player->AddGold(10);
		//player->AddItem(new Item()); 
		return false;
	}


	//player->TakeDamage(player->GetAttack()); //�÷��̾� ����
	if (_player->GetHealth() <= 0)
	{
		return false;
	}


	//���� ���� �ȳ����ٰ� �˷��ֱ�
	return true;
}