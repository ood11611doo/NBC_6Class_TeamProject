#include "MarketSystem.h"
#include "Database.h"
#include "Player.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

void MarketSystem::BuyItem(Player* pl, int itemIndex_, int buyCount_) {
	if (pl == nullptr) { return; }
	// 아이템벡터의 정보(주소나 개수)를 불러올 때 어떻게 ?
	if (pl->getNumOfItem() != nullptr && itemIndex_ == 0 ) { // 플레이어의 아이템 벡터에 접근 불가. hpPotion 객체를 불러오는 방법?
		if (pl->getGold() < ITEM_HEALING_PRICE * buyCount_) {
			return;
		}
		else {
			pl->setGold(pl->getGold() - (ITEM_HEALING_PRICE * buyCount_));// HealthPotion::AddCount(buyCount_); static 함수인 경우에만 유효함
			HealthPotion* hpPotion; // non-static 멤버함수는 반드시 객체(this)가 필요함, 객체 따로 생성하면 안될듯?
			hpPotion->AddCount(buyCount_);
			item[0]->SetCount(pl->ReturnItemCount(0) + buyCount_); // 안됨...
		}

	}
	else if (/*item[1] != nullptr*/ && itemIndex_ == 1) {
		if (pl->getGold() < ITEM_BUFFDAMAGE_PRICE * buyCount_) {
			return;
		}
		else {
			pl->setGold(pl->getGold() - (ITEM_BUFFDAMAGE_PRICE * buyCount_));
			AttackBoost* attBoost;
			attBoost->AddCount(buyCount_);
		}
	}
	else {
		return;
	}
}
// Todo : 아이템 구매 함수
		// Player를 포인터로 받아와서 사용하도록
		// 여기서 안전수단으로 Player 골드와 구매하려는 아이템 및 구매수량 등을 체크해서
		// 소유 골드보다 많을 경우 작동하지 않도록 해 주세요
// 아이템 수량 증가 및 골드 차감도 여기서 이루어지도록 해 주세요

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
