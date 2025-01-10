#pragma once
#include "BaseMonster.cpp"
#include "PlayerCharacter.h"
#include <iostream>
#include <string>
#include "EnemyFactory.h"


class BattleManager 
{

private:

	//���� ����
	BaseMonster* _currentMonster;
	EnemyFactory* _eFactory;
	//�̱��� �Ǹ� �ٲ��ٰ�
	PlayerCharacter* _player;


public:

	BaseMonster* GetMonster() const { return  _currentMonster; };

	// ������
	BattleManager()
		: _currentMonster(nullptr),
		_eFactory(new EnemyFactory()),
		_player(new PlayerCharacter())
	{

	}
	~BattleManager() {
		delete _currentMonster;
		delete _eFactory;
	}

	// true�ϰ�� ���� ��� false �ϰ�� ���� ��� 
	bool Battle();

};
