#pragma once
#include "Player.h"

class MarketSystem {
public:
	Player* pl;

	bool BuyItem(Player* pl, int itemIndex_, int buyCount_);
	bool SellItem(Player* pl, int itemIndex_,  int sellCount_);
};
