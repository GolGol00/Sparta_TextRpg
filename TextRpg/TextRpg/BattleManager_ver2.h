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

	//현재 몬스터
	BaseMonster* _currentMonster;
	EnemyFactory* _eFactory;
	//싱글톤 되면 바꿔줄것
	PlayerCharacter* _player;

	vector<float> _enemyrand;


	int Choose(const std::vector<float> probs);
	
	void  deleteMonster();


public:

	BaseMonster* GetMonster() const { return  _currentMonster; };

	// 생성자
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

	// true일경우 전투 계속 false 일경우 전투 취소 
	bool Battle();

};
