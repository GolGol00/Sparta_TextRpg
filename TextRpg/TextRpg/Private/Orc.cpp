#include <iostream>
#include "../Public/Orc.h"


using namespace std;

// 
void Orc::UseSkill()
{
	cout << GetName() << "��(��) �г� ���·� �����Ͽ� ���� ü���� ������ ȸ���մϴ�." << endl;
	CurrentHP += (MaxHP - CurrentHP) / 2;
}
