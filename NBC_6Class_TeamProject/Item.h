#pragma once
#include <string>
#include "Database.h"

class Player;

class Item {
	/*
	1. 아이템들(자식)의 갯수는 Player 클래스의 아이템자료형 백터에 쌓일 것
	2. 0번 인덱스 == HealthPotoin, 1번인덱스 == AttackBoost
	3. 첫 획득 시 생성자로 동적할당 그 다음부터 해당인덱스가 nullptr이 아니라면 Item획득 함수에서 게터와 세터를 활용 ++
	4. HeathPotion같은경우 전투종료와 상관이없지만 AttackBoost같은 경우 아이템 사용으로 증가한 전투력을 전투 종료시점에 초기화 필요
	5. 가능하다면 Player.h에 멤버변수로 increaseAttack 같은 추가 공격력 변수를 만들어 활용
	6. AttackBoost의 증가부분은 Player increaseAttack변수를 게터와 세터로 접근해 증가시키고 전투 종료시 초기화하는 방향으로
	*/
public:
	virtual ~Item() = default;

	virtual std::string GetName() const = 0;
	virtual int GetCount() const = 0;
	virtual int SetCount(int InCount) = 0;
	virtual int AddCount(int InCount) = 0;
	virtual void Use(Player* InPlayer) = 0;
};
