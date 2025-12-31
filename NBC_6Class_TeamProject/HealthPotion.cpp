#include "HealthPotion.h"
#include "Player.h"
#include <iostream>

using namespace std;

void HealthPotion::Use(Player* InPlayer) {
	if (GetCount() <= 0) {
		return;
	} else {
		SetCount(GetCount() - 1);
	}
	
	int newHealth = InPlayer->getHp() + healthRestore;

	if (newHealth > InPlayer->getMaxHp()) {
		InPlayer->setHp(InPlayer->getMaxHp());
	} else {
		InPlayer->setHp(newHealth);
	}
}
