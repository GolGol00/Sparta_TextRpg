#include "Framework.h"
#include <iostream>

void EnragedState::HandleState(BaseMonster* Monster)
{
	cout << Monster->GetName() << "��(��) �г� �����Դϴ�." << endl;
	Monster->UseSkill();
}
