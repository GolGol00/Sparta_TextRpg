#pragma once

#include <string>
#include "IState.h"

using namespace std;

class BaseMonster
{
protected:
	string Name;
	int MaxHP;
	int CurrentHP;
	int Damage;
	bool IsDead;
	IState* CurrentState; 

public:
	BaseMonster(const string& name, const int& PlayerLevel);
	virtual ~BaseMonster();

	// MaxHP�� Damage �ʱ�ȭ �޼���
	void Calculate_HPandDamage(const int& PlayerLevel);

	// �÷��̾�� ���� ������ ��, ������ ���� �޼���
	void TakeDamage(const int& DamagedAmount);

	// ���� ���� ���� �޼���
	void SetState(IState* NewState);

	// ���� ��ų ���� ���� �޼��� / ���� ���� �������� �������� �ٲ� �����Դϴ�.
	virtual void UseSkill() = 0;

	string GetName() { return Name; }
	int GetHP() { return CurrentHP; }
	int GetDamage() { return Damage; }
};
