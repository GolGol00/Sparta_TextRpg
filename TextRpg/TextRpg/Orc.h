#pragma once

#include "BaseMonster.h"


class Orc : public BaseMonster
{
public:
	Orc(const string& name, const int& PlayerLevel) : BaseMonster(name, PlayerLevel) {}

	void UseSkill() override;
};