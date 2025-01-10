#pragma once

#include "IBattleManager.h"
#include "Public/BaseMonster.h"

#include "PlayerCharacter.h"
#include "EnemyFactory.h"


class BattleManager : public IBattleManager
{

private:

	//현재 몬스터
	BaseMonster* _currentMonster;
	EnemyFactory* _eFactory;
	//싱글톤 되면 바꿔줄것
	PlayerCharacter* _player;

	void deleteMonster() {
		delete _currentMonster; // 몬스터 메모리 해제
		_currentMonster = nullptr; // 몬스터 초기화
	}

public:

	// 생성자
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
	

	//몬스터가 체력이 있을경우
	bool IsCanBattle() const	{return _currentMonster->GetHP() > 0;	}


	

	void SummonMonster();

	bool Fight();




};