#include "MarketSystem.h"
#include "Database.h"
#include "Player.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

void MarketSystem::BuyItem(Player* pl, int itemIndex_, int buyCount_) {
	if (pl == nullptr) { return; }
	int priceItem = 0;
	if (pl->getNumOfItem()[itemIndex_] == nullptr) {
		priceItem = GetBasicPrice(itemIndex_);
	} else {
		priceItem = pl->getNumOfItem()[itemIndex_]->GetPrice();
	}
	priceItem *= buyCount_;

	if (pl->getGold() < priceItem) {
		return;
	}

	for (int i = 0; i < buyCount_; i++) {
		pl->AddItemByIndex(itemIndex_);
	}
	pl->setGold(pl->getGold() - priceItem);
}

void MarketSystem::SellItem(Player* pl, int itemIndex_, int sellCount) {
	std::string item = "";

	if (/*item[0] != nullptr*/ && itemIndex_ == 0) {
		// Item* item;
		if (pl->ReturnItemCount(0) >= sellCount) {
			HealthPotion.Setcount(pl->ReturnItemCount(0) - sellCount); // 팔고 남은 개수 입력(다시)
			pl->setGold(pl->getGold() + sellCount * ITEM_HEALING_PRICE)
		}
	}
	else if (/*item[1] != nullptr*/ && itemIndex_ == 1) {
		if (pl->ReturnItemCount(1) >= sellCount) {
			// 가진 개수 - 판매 개수
			pl->setGold(pl->getGold() + sellCount * ITEM_BUFFDAMAGE_PRICE)
		}
	}
	else {
		return;
	}
}
// Todo : 아이템 판매 함수
// Player를 포인터로 받아와서 사용하도록
// 여기서도 안전수단으로 아이템 판매 원하는 수량과 아이템이 실제로 몇 개 있는지 체크해서
// 판매 수량이 보유 수량보다 많을 경우 작동하지 않도록 해 주셰요
// 아이템 수량 증가 및 골드 차감도 여기서 이루어지도록 해 주셰요
