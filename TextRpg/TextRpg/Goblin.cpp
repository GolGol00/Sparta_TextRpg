#include <iostream>
#include "../Public/Goblin.h"


using namespace std;


void Goblin::UseSkill()
{
	cout << GetName() << "��(��) ���ݷ��� 2�� ����մϴ�." << endl;
	Damage *= 2;
}