#include <iostream>
#include "Orc.h"



using namespace std;


void Orc::UseSkill()
{
	cout << GetName() << "��(��) ���� ü���� ������ ȸ���մϴ�." << endl;
	CurrentHP += (MaxHP - CurrentHP) / 2;
}