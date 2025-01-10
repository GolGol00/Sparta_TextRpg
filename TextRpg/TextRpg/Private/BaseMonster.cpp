
#include "BaseMonster.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Public/BaseMonster.h"

using namespace std;


BaseMonster::BaseMonster(const string& name, const int& PlayerLevel)
{
	Name = name;
	Calculate_HPandDamage(PlayerLevel);
	CurrentHP = MaxHP;
	IsDead = false;
}

// MaxHP�� Damage �ʱ�ȭ �޼���
void BaseMonster::Calculate_HPandDamage(const int& PlayerLevel)
{
	//srand(time(0)); ���� �����Լ����� �� ���� ���
	int HP_Multiplier = (rand() % 11) + 20;
	int Damage_Multiplier = (rand() % 6) + 5;

	MaxHP = PlayerLevel * HP_Multiplier;
	Damage = PlayerLevel * Damage_Multiplier;
}

// ������ ���� �޼���
void BaseMonster::TakeDamage(const int& DamagedAmount)
{
	CurrentHP -= DamagedAmount;
	if (CurrentHP < 0)
	{
		CurrentHP = 0;
		IsDead = true;
		return;
	}
}