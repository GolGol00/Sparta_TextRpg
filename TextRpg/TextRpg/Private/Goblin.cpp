#include <iostream>
#include "../Public/Goblin.h"
#include "Goblin.h"

using namespace std;


void Goblin::UseSkill()
{
	cout << GetName() << "이(가) 분노 상태로 돌입하여 공격력이 상승합니다." << endl;
	Damage *= 2;
}