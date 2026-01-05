#pragma once
#include "Item.h"

class HealthPotion : public Item {
private:
	std::string name;
	int healthRestore;
	int price;
	int count = 0;

public:
	HealthPotion() :
		name(ITEM_HEALING_NAME),
		healthRestore(ITEM_HEALING_VALUE),
		price(ITEM_HEALING_PRICE),
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