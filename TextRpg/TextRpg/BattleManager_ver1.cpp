#include "Framework.h"

void Battle_Ver_1::BattleManager::SummonMonster() {

		if (_currentMonster != nullptr)
		{
			deleteMonster();
		}
		_eFactory->getMonster(1, 1);

}

bool Battle_Ver_1::BattleManager::Fight() {
	//_currentMonster->TakeDamage(_player->GetAttack());

	if (_currentMonster->GetHP() <= 0) {

		//_player->AddExperience(50);
		//_player->AddGold(10);

		deleteMonster();

		return false;
	}

	// 몬스터 공격
	//player->TakeDamage(CurrentMonster->GetDamage());

	/*if (_player->GetHealth() <= 0) {
		return false;
	}*/

	//전투 아직 안끝났다고 알려주기
	return true;
}