#pragma once
#include <random>
#include <string>

class Monster {
private:
	std::string MonsterName;
	int MonsterHp;
	int MonsterAttack;
	// string RecentMonsterName; // 객체 사라지면 같이 삭제됨 --> 배틀매니저
	// 둘내님 이거 매니저에 넣어주세요

public:

	Monster(int plLevel, std::string RecentMonsterName);

	std::string GetMonsterName() { return MonsterName; }
	void SetMonsterName(std::string name) { MonsterName = name; }

	int GetMonsterHp() { return MonsterHp; }
	void SetMonsterHp(int hp) { MonsterHp = hp; } // 필요?
	
	int GetMonsterAttack() { return MonsterAttack; }
	void SetMonsterAttack(int attack) { MonsterAttack = attack; }

	int TakeDamage(int damage);

	std::string PrintMonsterStatus();
};
