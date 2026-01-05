#pragma once
#include "Item.h"

class AttackBoost : public Item {
private:
	std::string name;
	int attackIncrease;
	int price;
	int count = 0;

public:
	AttackBoost()
		: name(ITEM_BUFFDAMAGE_NAME),
		attackIncrease(ITEM_BUFFDAMAGE_VALUE),
		price(ITEM_BUFFDAMAGE_PRICE),
		count(1) {}

	std::string GetName() const override { return name; }

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
