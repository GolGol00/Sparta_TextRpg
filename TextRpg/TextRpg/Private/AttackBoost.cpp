#include "AttackBoost.h"

AttackBoost::AttackBoost() : ItemName("AttackBoost"), TargetStat(ATTACK)
{
}

void AttackBoost::Use(PlayerCharacter* character)
{
	character->IncreaseStat(TargetStat, StatAmount);
}

void AttackBoost::PrintItemInfo()
{
}
