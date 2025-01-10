#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Public/BaseMonster.h"
#include "EnemyFactory.h"
#include "PlayerCharacter.h"





class BattleManager 
{

private:

	//���� ����
	BaseMonster* _currentMonster;
	EnemyFactory* _eFactory;
	//�̱��� �Ǹ� �ٲ��ٰ�
	PlayerCharacter* _player;

	vector<float> _enemyrand;


	int Choose(const std::vector<float> probs);
	
	void  deleteMonster();


public:

	BaseMonster* GetMonster() const { return  _currentMonster; };

	// ������
	BattleManager()
		: _currentMonster(nullptr),
		_eFactory(new EnemyFactory()),
		_player(new PlayerCharacter())
	{
		_enemyrand = { 50.0f , 50.0f };
	}
	~BattleManager() {
		delete _currentMonster;
		delete _eFactory;
	}

	// true�ϰ�� ���� ��� false �ϰ�� ���� ��� 
	bool Battle();

};
