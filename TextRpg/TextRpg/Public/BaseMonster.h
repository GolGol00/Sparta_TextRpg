#pragma once

#include <string>

using namespace std;

class BaseMonster
{
protected:
	string Name;
	int MaxHP;
	int CurrentHP;
	int Damage;
	bool IsDead;

public:
	BaseMonster(const string& name, const int& PlayerLevel);

	// MaxHP�� Damage �ʱ�ȭ �޼���
	void Calculate_HPandDamage(const int& PlayerLevel);

	// �÷��̾�� ���� ������ ��, ������ ���� �޼���
	void TakeDamage(const int& DamagedAmount);

	// ���� ��ų ���� ���� �޼��� / ���� ���� �������� �������� �ٲ� �����Դϴ�.
	virtual void UseSkill() = 0;

	string GetName() { return Name; }
	int GetHP() { return CurrentHP; }
	int GetDamage() { return Damage; }
};
