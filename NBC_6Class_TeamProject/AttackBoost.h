#pragma once
#include "Item.h"


using namespace std;

class AttackBoost : public Item {
private:
	string name;
	int attackIncrease;
	int count = 0;
public:
	// Item* 백터의 0번이 nullptr이라면 획득과 동시에 갯수 1개 와 기본 아이템 정보 입력
	// nullptr이 아니라면 획득 -> GetCount로 현재 갯수 불러와서 + 1 한다음 SetCount에 넣어주도록
	AttackBoost() : name(ITEM_BUFFDAMAGE_NAME), attackIncrease(ITEM_BUFFDAMAGE_VALUE), count(1) {}
	string GetName() const override { return name; }
	int GetCount() const { return count; }
	int SetCount(int InCount) override {
		count = InCount;
		return count;
	}
	int AddCount(int InCount) override {
		count += InCount;
		return count;
	}
	void Use(Player* InPlayer) override;
};
