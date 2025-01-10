#include "EnemyFactory.h"




BaseMonster* EnemyFactory::getMonster(int id, int level) 
{
	switch (id)
	{
	case 1:
		return new Goblin("고블린", 1);

	case 2:
		return new Orc("오크", 2);
	default:
		break;
	}
}