#pragma once

#include "BaseMonster.h"

// �� ���� Ŭ���� ��ų�� ���� ����� �� �ֽ��ϴ�.
class Goblin : public BaseMonster
{
public:
	Goblin(const string& name, const int& PlayerLevel) : BaseMonster(name, PlayerLevel) {}

	void UseSkill() override;

};