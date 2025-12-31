#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include "Player.h"

using namespace std;


Player::Player() : level(1), hp(200), max_hp(200), atkpower(30), extraatk(10), exp(0), gold(0) {
	name = " ";
}

Player::Player(string name) : level(1), hp(200), max_hp(200), atkpower(30), extraatk(10), exp(0), gold(0) {
	this->name = name;
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

void Player::UseItem(int itemIndex) {

	if (itemIndex >= 0 && itemIndex < item.size()) {
		if (itemIndex == 0) {
			//item[0] = new HealthPotion
			if((item[0]->GetCount())>0)
				item[0]->Use(pl);
				hp += 50;
				if (hp > max_hp) {
					hp = max_hp;
				}
		}
		else if (itemIndex == 1) {
			//item[1] = new AttackBoost
			if((item[1]->GetCount()>0))
				item[1]->Use(pl);
				extraatk = 10;
		}// 수정
	}
}

int Player::TakeDamage(int damage) {
	hp -= damage;

	if (hp <= 0)
		hp = 0;

	return hp;
}