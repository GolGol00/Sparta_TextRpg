#include "BattleManager_ver2.h"



void  BattleManager::deleteMonster() {
	delete _currentMonster; // 몬스터 메모리 해제
	_currentMonster = nullptr; // 몬스터 초기화
}

int BattleManager::Choose(const std::vector<float> probs)
{
	float total = 0;

	//확률 총합
	for (float i : probs)
	{
		total += i;
	}

	float randomPoint = static_cast<float>(std::rand()) / RAND_MAX * total;


	//랜덤값과 비교하여 확률이 더크면 해당 인덱스 전달  //해당 인덱스의 확률이 당첨
	for (size_t i = 0; i < probs.size(); i++)
	{
		if (randomPoint < probs[i])
		{
			return i;
		}
		else {
			randomPoint -= probs[i];
		}
	}


}


bool BattleManager::Battle() {
	//먼저 존재 확인
	if (_player == nullptr)
	{
		return false;
	}

	if (_currentMonster == nullptr)
	{
		_currentMonster = _eFactory->getMonster(Choose(_enemyrand), _player.GetLevel());
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

		//몬스터 삭제
		deleteMonster();

		//죽었으니 보상
		_player->IncreaseStat();
		_player->IncreaseStat();
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