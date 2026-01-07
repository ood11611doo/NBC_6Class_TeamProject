#pragma once
#include <random>
#include <string>
#include <vector>

class Monster {
private:
	std::string MonsterName;
	int MonsterHp;
	int MonsterAttack;
	bool isBossMonster;

public:

	Monster(int plLevel, std::string RecentMonsterName);
	Monster(int plLevel, std::string RecentMonsterName, bool isBoss);

	std::string GetMonsterName() { return MonsterName; }
	void SetMonsterName(std::string name) { MonsterName = name; }

	int GetMonsterHp() { return MonsterHp; }
	void SetMonsterHp(int hp) { MonsterHp = hp; }
	
	int GetMonsterAttack() { return MonsterAttack; }
	void SetMonsterAttack(int attack) { MonsterAttack = attack; }

	int TakeDamage(int damage);
	std::string PrintMonsterStatus();
	void SetMonsterToBoss(int plLevel);
};
