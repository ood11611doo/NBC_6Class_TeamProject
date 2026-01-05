#include "MarketSystem.h"
#include "Database.h"
#include "Player.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

bool MarketSystem::BuyItem(Player* pl, int itemIndex_, int buyCount_) {
	if (pl == nullptr) { return false; }

	int priceItem = 0;

	if (pl->getNumOfItem()[itemIndex_] == nullptr) {
		priceItem = GetBasicPrice(itemIndex_);
	} else {
		priceItem = pl->getNumOfItem()[itemIndex_]->GetPrice();
	}
	priceItem *= buyCount_;

	if (pl->getGold() < priceItem) { return false; }

	for (int i = 0; i < buyCount_; i++) {
		pl->AddItemByIndex(itemIndex_);
	}
	pl->addGold(-priceItem);

	return true;
}

bool MarketSystem::SellItem(Player* pl, int itemIndex_, int sellCount_) {
	if (pl == nullptr) { return false; }
	if (pl->getNumOfItem()[itemIndex_] == nullptr) { return false; }
	if (sellCount_ > pl->getNumOfItem()[itemIndex_]->GetCount()) { return false; }

	int cellItemPrice = GetCellPrice(itemIndex_);

	pl->RemoveItem(itemIndex_, sellCount_);
	pl->addGold(cellItemPrice * sellCount_);
	return true;
}