#include "AttackBoost.h"
#include "Player.h"
#include <iostream>

using namespace std;

void AttackBoost::Use(Player* InPlayer) {
	if (GetCount() <= 0) {
		return;
	} else {
		SetCount(GetCount() - 1);
	}

	int newExtraAttack = InPlayer->getExtraAtk() + attackIncrease;
	InPlayer->setExtraAtk(newExtraAttack);
}
