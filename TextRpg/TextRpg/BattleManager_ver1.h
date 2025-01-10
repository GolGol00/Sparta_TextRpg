#pragma once

#include "IBattleManager.h"
#include "Public/BaseMonster.h"

#include "PlayerCharacter.h"
#include "EnemyFactory.h"


class BattleManager : public IBattleManager
{

private:

	//���� ����
	BaseMonster* _currentMonster;
	EnemyFactory* _eFactory;
	//�̱��� �Ǹ� �ٲ��ٰ�
	PlayerCharacter* _player;

	void deleteMonster() {
		delete _currentMonster; // ���� �޸� ����
		_currentMonster = nullptr; // ���� �ʱ�ȭ
	}

public:

	// ������
	BattleManager()
		: _currentMonster(nullptr),
		_eFactory(new EnemyFactory()),
		_player(new PlayerCharacter())
	{
		//_player = PlayerCharacter.GetInstance(name);
	}
	~BattleManager() {
		delete _currentMonster;
		delete _eFactory;
	}

	
	BaseMonster* GetMonster() const { return  _currentMonster; };
	

	//���Ͱ� ü���� �������
	bool IsCanBattle() const	{return _currentMonster->GetHP() > 0;	}


	

	void SummonMonster();

	bool Fight();




};