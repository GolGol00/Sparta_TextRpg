#include "BaseMonster.h"
#include "NormalState.h"
#include "EnragedState.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


BaseMonster::BaseMonster(const string& name, const int& PlayerLevel)
{
	Calculate_HPandDamage(PlayerLevel);

	Name = name;
	CurrentHP = MaxHP;
	IsDead = false;

	CurrentState = new NormalState(); //���� ��ü ���� ����
}

BaseMonster::~BaseMonster()
{
	delete CurrentState; // ���� ��ü ���� ����
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

	if (CurrentHP <= MaxHP / 2)
	{
		SetState(new EnragedState());
	}
}

// ���� ���� ���� �޼���
void BaseMonster::SetState(IState* NewState)
{
	if (CurrentState)
	{
		delete CurrentState;
	}
	CurrentState = NewState;
}
