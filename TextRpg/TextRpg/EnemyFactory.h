#pragma once
#include "BaseMonster.h"
#include "Goblin.h"
#include "Orc.h"





class EnemyFactory {

public:

	//아직 플레이어 스크립트 안넣어줬음.
	//가능하면 템플릿도 괜찮아보이네요	
	BaseMonster* getMonster(int id, int level);
	
};
