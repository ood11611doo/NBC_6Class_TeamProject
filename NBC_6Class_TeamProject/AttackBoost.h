#pragma once
#include "Item.h"


using namespace std;

class AttackBoost : public Item {
private:
	string name;
	int attackIncrease;
	// Item* 백터의 0번에 HealthPotion, 1번에 AttackBoost를 지정해서 쓴다면 갯수 변수가 필요
	int count = 0;
public:
	// Item* 백터의 0번이 nullptr이라면 획득과 동시에 갯수 1개 와 기본 아이템 정보 입력
	// nullptr이 아니라면 획득 -> GetCount로 현재 갯수 불러와서 + 1 한다음 SetCount에 넣어주도록
	AttackBoost() : name("AttackBoost"), attackIncrease(ITEM_BUFFDAMAGE_VALUE), count(1) {}
	// getter함수
	string GetName() const override { return name; }
	int GetCount() const { return count; }
	// setter 함수
	// 아이템 갯수 변동 시 GetCount에 변동 갯수를 반영해 SetCount로 수정
	// count를 return 획득한 후의 물약 갯수 출력
	int SetCount(int InCount) override {
		count = InCount;
		return count;
	}
	// 물약 사용
	void Use(Player* InPlayer) override;
};
