
#include "Framework.h"

HealthPotion::HealthPotion() : ItemName("HealthPotion")
{
}

void HealthPotion::Use(PlayerCharacter* character)
{
	character->IncreaseStat(HP, StatAmount);
}

void HealthPotion::PrintItemInfo()
{
}