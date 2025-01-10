#include "EnemyFactory.h"




BaseMonster* EnemyFactory::getMonster(int id, int level) 
{
	switch (id)
	{
	case 1:
		return new Goblin("���", level);

	case 2:
		return new Orc("��ũ", level);
	default:
		break;
	}
}