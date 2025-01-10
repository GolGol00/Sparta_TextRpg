#pragma once

#include "IState.h"


class NormalState : public IState
{
public:
	void HandleState(BaseMonster* Monster) override;

};