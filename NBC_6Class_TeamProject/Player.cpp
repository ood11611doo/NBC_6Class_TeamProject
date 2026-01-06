#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include "Player.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

using namespace std;

Player::Player() : level(1), hp(200), max_hp(200), atkpower(30), extraatk(10), exp(0), gold(0) {
	name = " ";
	item = vector<Item*>(10, nullptr);
}

Player::Player(string name) : level(1), hp(200), max_hp(200), atkpower(30), extraatk(10), exp(0), gold(0) {
	this->name = name;
	item = vector<Item*>(10, nullptr);
}
Player::~Player() {
	for (const auto& items : item) {
		if (items != nullptr) {
			delete items;
		}
	}
}

void Player::CheckLevelUp() {
	//exp += 50;
	if (exp < 100 || level >= 10)
		return;

	level += 1;
	exp -= 100;

	max_hp += level * 20;
	hp = max_hp;
	atkpower += level * 5;
}

string Player::PrintPlayerStatus() {
	stringstream status;
	status << "이름:" << name << " | 레벨:" << level << " | 현재 체력:" << hp << "/" << max_hp;
	status << " | 공격력:" << atkpower + extraatk << " | 경험치:" << exp << " | 현재 골드:" << gold << "\n";
	//아이템 출력 추가되야?
	for (const auto& itemIn : item) {
		if (itemIn != nullptr && itemIn->GetCount() > 0) {
			status << itemIn->GetName() << ": " << itemIn->GetCount() << "\n";
		}
	}
	
	string playerstatus = status.str();
	return playerstatus;
}
string Player::PrintEXPAndGold() {
	string expGoldReturn;
	expGoldReturn += "현재 EXP: " + to_string(exp) + "/" + to_string(PLAYER_MAX_EXP) + ", ";
	expGoldReturn += "골드: " + to_string(gold);
	return expGoldReturn;
}

void Player::UseItem(int itemIndex) {
	if (itemIndex >= 0 && itemIndex < item.size()) {
		if (item[itemIndex] != nullptr && (item[itemIndex]->GetCount()) > 0) {
			item[itemIndex]->Use(this);
		}
	}
}
void Player::RemoveItem(int itemIndex, int count) {
	if (itemIndex >= 0 && itemIndex < item.size()) {
		int desiredCountDec = count;
		if (item[itemIndex] != nullptr && item[itemIndex]->GetCount() < count) {
			desiredCountDec = item[itemIndex]->GetCount();
		}
		item[itemIndex]->SetCount(item[itemIndex]->GetCount() - desiredCountDec);
	}
}

int Player::TakeDamage(int damage) {
	hp -= damage;

	if (hp <= 0)
		hp = 0;

	return hp;
}

void Player::AddItemByIndex(int addIndex) {
	if (item[addIndex] == nullptr) {
		if (addIndex == 0) {
			item[addIndex] = new HealthPotion();
		} else if (addIndex == 1) {
			item[addIndex] = new AttackBoost();
		}
		return;
	}

	item[addIndex]->AddCount(1);
}

int Player::ReturnItemCount(int itemIndex) {
	if (item[itemIndex] == nullptr) {
		return 0;
	}
	return item[itemIndex]->GetCount();
}

string Player::GetItemName(int itemIndex) {
	if (itemIndex == 0) return ITEM_HEALING_NAME;
	else if (itemIndex == 1) return ITEM_BUFFDAMAGE_NAME;
	return "";
}