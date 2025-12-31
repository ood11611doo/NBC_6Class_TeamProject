#pragma once
#include <string>
#include "Database.h"

class Player;

using namespace std;

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
	// 어차피 자식클래스들에서 멤버변수와 함수를 각자 다르게 할 예정
	// 가상함수 선언 + 소멸자만 선언
	// getter 함수
	virtual string GetName() const = 0;
	virtual int GetCount() const = 0;
	// setter 함수
	virtual int SetCount(int InCount) = 0;
	// Use(Character* pl)
	virtual void Use(Player* InPlayer) = 0;
	// 소멸자
	virtual ~Item() = default;
};
