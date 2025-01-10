#include "BattleManager_ver2.h"


bool BattleManager::Battle() {
	//먼저 존재 확인
	if (_player == nullptr)
	{
		return false;
	}

	if (_currentMonster == nullptr)
	{
		_currentMonster = _eFactory->getMonster(1, 1);
	}

	//몬스터 없으면 몬스터 생성

	//먼저 HP확인
	if (_player->GetHealth() <= 0 || _currentMonster->GetHP() <= 0)
	{
		return false;
	}

	//현재 체력 보다 많을경우 아이템사용
	if (_player->GetHealth() <= _currentMonster->GetDamage())
	{
		_player->UseItem(0);
	}



	//1. 플레이어 공격 2. 몬스터공격

	_currentMonster->TakeDamage(_player->GetAttack());

	//먼저 HP확인 // 이부분 나중에 TakeDamage() 같은 데미지 받는 함수들일 경우 반환값		
	if (_currentMonster->GetHP() <= 0)
	{
		//죽었으니 보상
		_player->AddExperience(50);
		_player->AddGold(10);
		//player->AddItem(new Item()); 
		return false;
	}


	//player->TakeDamage(player->GetAttack()); //플레이어 공격
	if (_player->GetHealth() <= 0)
	{
		return false;
	}


	//전투 아직 안끝났다고 알려주기
	return true;
}