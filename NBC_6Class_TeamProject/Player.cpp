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
	status << " | 공격력:" << atkpower + extraatk << " | 경험치:" << exp << " | 현재 골드:" << gold;
	//아이템 출력 추가되야?
	
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
		if (itemIndex == 0) {
			if((item[0]->GetCount())>0)
				item[0]->Use(this);
		}
		else if (itemIndex == 1) {
			if((item[1]->GetCount()>0))
				item[1]->Use(this);
		}
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