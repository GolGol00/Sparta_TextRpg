#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include "PlayerCharacter.h"

using namespace std;

class Item
{
public:
	// 아이템 이름 반환
	virtual string GetName() const = 0;
	// 아이템이 변경할 스탯 enum 반환
	virtual STATUS GetTargetStat() const = 0;
	// 아이템이 변경할 스탯 수치
	virtual int GetStatAmount() const = 0;
	// 아이템 정보 출력
	virtual void PrintItemInfo() = 0;

	virtual void Use(PlayerCharacter* character) = 0;
};

#endif