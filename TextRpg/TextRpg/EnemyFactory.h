#pragma once
#include "BaseMonster.h"




class EnemyFactory {

public:

	//���� �÷��̾� ��ũ��Ʈ �ȳ־�����.
	//�����ϸ� ���ø��� �����ƺ��̳׿�	
	BaseMonster* getMonster(int id, int level);
	
};
