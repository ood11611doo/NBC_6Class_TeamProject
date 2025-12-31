#include "AttackBoost.h"
#include <iostream>

using namespace std;

void AttackBoost::Use(Player* InPlayer)
{
	// 예외사항으로 물약이 없다면 수량부족 문구와 같이 return
	if (GetCount() <= 0)
	{
		return;
	}
	else
	{
		SetCount(GetCount() - 1);
	}

	// 임시 변수값 -> 플레이어의 현재 추가 공격력 + attackIncrease을 게터와 attackIncrease의 합으로 임시 변수값에 저장
	//int newExtraAttack = InPlayer->getExtraAttack() + attackIncrease;
	// 플레이어의 ExtraAttack변수에 세터로 newAttack으로 변경
	//InPlayer->setExtraAttack(newExtraAttack);
}
