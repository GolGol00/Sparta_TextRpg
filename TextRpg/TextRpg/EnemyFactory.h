#pragma once
#include "Public/BaseMonster.h"
#include "Public/Goblin.h"
#include "Public/Orc.h"





class EnemyFactory {

public:

	//���� �÷��̾� ��ũ��Ʈ �ȳ־�����.
	//�����ϸ� ���ø��� �����ƺ��̳׿�	
	BaseMonster* getMonster(int id, int level);
	
};
