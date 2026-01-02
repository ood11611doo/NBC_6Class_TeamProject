#pragma once
#include "Item.h"

class HealthPotion : public Item {
private:
	std::string name;
	int healthRestore;
	int price; // Todo : 아이템 가격 변수 생성 완료
	int count = 0;

public:
	// Todo : 아이템 생성 시 가격 변수값 설정
	HealthPotion() :
		name(ITEM_HEALING_NAME),
		healthRestore(ITEM_HEALING_VALUE),
		price(ITEM_HEALING_PRICE),
		count(1) {
	}

	std::string GetName() const override { return name; }

	// Todo : 가상함수 override받은 가격을 return해주는 함수 생성
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