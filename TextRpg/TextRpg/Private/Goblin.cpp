#include <iostream>
#include "../Public/Goblin.h"


using namespace std;


void Goblin::UseSkill()
{
	cout << GetName() << "��(��) �г� ���·� �����Ͽ� ���ݷ��� ����մϴ�." << endl;
	Damage *= 2;
}