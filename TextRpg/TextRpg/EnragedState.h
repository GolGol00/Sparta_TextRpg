#pragma once

#include "IState.h"


class EnragedState : public IState
{
	void HandleState(BaseMonster* Monster) override;
};