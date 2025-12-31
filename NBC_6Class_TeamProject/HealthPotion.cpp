#include "HealthPotion.h"
#include <iostream>

using namespace std;

// Use(Character* pl) - 캐릭터가 사용하고 스탯 조절

void HealthPotion::Use(Player* InPlayer)
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
	
	////임시 변수값 -> 플레이어의 현재 체력 + healthRestore을 게터와 healthRestore의 합으로 임시 변수값에 저장
	//int newHealth = InPlayer->getHealth() + healthRestore;
	//// 회복량이 최대 체력을 넘어간다면 최대 체력 까지만 회복
	//if (newHealth > InPlayer->getMaxHealth())
	//{
	//	InPlayer->setHealth(InPlayer->getMaxHealth())
	//}
	//else
	//{
	//	// 아니라면 newHealth값 적용
	//	InPlayer->setHealth(newHealth);
	//}
	
}
