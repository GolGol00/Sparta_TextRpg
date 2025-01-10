#include "HealthPotion.h"

HealthPotion::HealthPotion() : ItemName("HealthPotion"), TargetStat(HP)
{
}

void HealthPotion::Use(PlayerCharacter* character)
{
	character->IncreaseStat(TargetStat, StatAmount);
}

void HealthPotion::PrintItemInfo()
{
}

