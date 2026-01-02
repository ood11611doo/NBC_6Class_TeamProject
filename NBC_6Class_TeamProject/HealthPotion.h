#pragma once
#include "Item.h"

using namespace std;

class HealthPotion : public Item {
private:
	string name;
	int healthRestore;
	// Todo : 아이템 가격 변수 생성 필요
	int count = 0;
public:
	// Todo : 아이템을 생성할 때, 해당 아이템의 가격 변수값도 설정할 수 있도록
	HealthPotion() : name(ITEM_HEALING_NAME), healthRestore(ITEM_HEALING_VALUE), count(1) {}
	string GetName() const override { return name; }
	// Todo : 가상함수 override받은 가격을 return해주는 함수 생성
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
