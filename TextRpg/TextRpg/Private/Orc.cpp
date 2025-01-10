#include <iostream>
#include "../Public/Orc.h"
#include "Orc.h"

using namespace std;

// 
void Orc::UseSkill()
{
	cout << GetName() << "이(가) 분노 상태로 돌입하여 잃은 체력의 절반을 회복합니다." << endl;
	CurrentHP += (MaxHP - CurrentHP) / 2;
}
