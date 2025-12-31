#include "AttackBoost.h"
#include <iostream>

using namespace std;

void AttackBoost::Use(Player* InPlayer)
{
	// 예외사항으로 물약이 없다면 수량부족 문구와 같이 return
	if (GetCount() <= 0)
	{
		cout << name << "의 수량이 부족하여 사용할 수없습니다." << '\n';
		return;
	}
	else
	{
		SetCount(GetCount() - 1);
	}

	//임시 변수값 -> 플레이어의 현재 공격력 + attackIncrease을 게터와 attackIncrease의 합으로 임시 변수값에 저장
	//int newAttack = InPlayer->getAttack() + attackIncrease;
	//InPlayer->setHealth(newAttack);


}
