#pragma once
#include "Player.h"

class MarketSystem {
public:
	// Todo : 아이템 구매 함수
	// Player를 포인터로 받아와서 사용하도록
	// 여기서 안전수단으로 Player 골드와 구매하려는 아이템 및 구매수량 등을 체크해서
	// 소유 골드보다 많을 경우 작동하지 않도록 해 주세요
	// 아이템 수량 증가 및 골드 차감도 여기서 이루어지도록 해 주세요
	void BuyItem(Player* pl);
	// Todo : 아이템 판매 함수
	// Player를 포인터로 받아와서 사용하도록
	// 여기서도 안전수단으로 아이템 판매 원하는 수량과 아이템이 실제로 몇 개 있는지 체크해서
	// 판매 수량이 보유 수량보다 많을 경우 작동하지 않도록 해 주셰요
	// 아이템 수량 증가 및 골드 차감도 여기서 이루어지도록 해 주셰요
	void SellItem(Player* pl);
};
