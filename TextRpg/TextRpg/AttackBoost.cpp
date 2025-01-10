#include "Framework.h"
#include "AttackBoost.h"


AttackBoost::AttackBoost() : ItemName("AttackBoost")
{
}

void AttackBoost::Use(PlayerCharacter* character)
{
	character->IncreaseStat(ATTACK, StatAmount);
}

void AttackBoost::PrintItemInfo()
{
}