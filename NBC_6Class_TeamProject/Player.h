#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Player {
private:

	string name;
	int level;
	int hp;
	int max_hp;
	int atkpower;
	int extraatk;
	int exp;
	int gold;
	vector <Item*> item = vector <Item*>(10, nullptr);

public:

	Player();
	Player(string name);

	// - Todo : getter, setter 함수 선언 필요
	string getName() const { return name; }
	void setName(string name) { this->name = name; }

	int getLevel() const { return level; }
	void setLevel(int level) { this->level = level; }

	int getHp() const { return hp; }
	void setHp(int hp) { this->hp = hp; }

	int getMaxHp() const { return max_hp; }
	void setMaxHp(int max_hp) { this->max_hp = max_hp; }

	int getAtkPower() const { return atkpower; }
	void setAtkPower(int atkpower) { this->atkpower = atkpower; }

	int getExtraAtk() const { return extraatk; }
	void setExtraAtk(int extraatk) { this->extraatk = extraatk; }

	int getExp() const { return exp; }
	void setExp(int exp) { this->exp = exp; }

	int getGold() const { return gold; }
	void setGold(int gold) { this->gold = gold; }

	vector <Item*> getNumOfItem() const { return item; }

	void CheckLevelUp();
	string PrintPlayerStatus();
	void UseItem(int itemIndex);
	int TakeDamage(int damage);
};
