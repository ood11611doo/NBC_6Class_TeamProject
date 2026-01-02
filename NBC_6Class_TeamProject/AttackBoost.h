#pragma once
#include "Item.h"

class AttackBoost : public Item {
private:
	std::string name;
	int attackIncrease;
	int price; // Todo : 아이템 가격 변수 생성
	int count = 0;

public:
	// 생성자에서 아이템 가격 설정
	AttackBoost()
		: name(ITEM_BUFFDAMAGE_NAME),
		attackIncrease(ITEM_BUFFDAMAGE_VALUE),
		price(ITEM_BUFFDAMAGE_PRICE),
		count(1) {}

	std::string GetName() const override { return name; }

	// 가상함수 override받은 가격을 return
	int GetPrice() const override { return price; }
	int GetCount() const override { return count; }

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
