
#include "Orc.h"
#include <iostream>

using namespace std;


void Orc::UseSkill()
{
	cout << GetName() << "이(가) 잃은 체력의 절반을 회복합니다." << endl;
	CurrentHP += (MaxHP - CurrentHP) / 2;
}
