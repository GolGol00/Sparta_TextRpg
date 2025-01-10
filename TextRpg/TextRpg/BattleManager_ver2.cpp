#include "BattleManager_ver2.h"



void  BattleManager::deleteMonster() {
	delete _currentMonster; // ���� �޸� ����
	_currentMonster = nullptr; // ���� �ʱ�ȭ
}

int BattleManager::Choose(const std::vector<float> probs)
{
	float total = 0;

	//Ȯ�� ����
	for (float i : probs)
	{
		total += i;
	}

	float randomPoint = static_cast<float>(std::rand()) / RAND_MAX * total;


	//�������� ���Ͽ� Ȯ���� ��ũ�� �ش� �ε��� ����  //�ش� �ε����� Ȯ���� ��÷
	for (size_t i = 0; i < probs.size(); i++)
	{
		if (randomPoint < probs[i])
		{
			return i;
		}
		else {
			randomPoint -= probs[i];
		}
	}


}


bool BattleManager::Battle() {
	//���� ���� Ȯ��
	if (_player == nullptr)
	{
		return false;
	}

	if (_currentMonster == nullptr)
	{
		_currentMonster = _eFactory->getMonster(Choose(_enemyrand), _player.GetLevel());
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

		//���� ����
		deleteMonster();

		//�׾����� ����
		_player->IncreaseStat();
		_player->IncreaseStat();
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