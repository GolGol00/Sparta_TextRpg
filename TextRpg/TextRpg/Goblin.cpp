#include "Goblin.h"
#include <iostream>

using namespace std;


void Goblin::UseSkill()
{
	cout << GetName() << "이(가) 공격력이 2배 상승합니다." << endl;
	Damage *= 2;
}