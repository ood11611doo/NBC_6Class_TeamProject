#pragma once
#include <random>
#include <string>

using namespace std;

class Monster {
private:

	string MonsterName;
	int MonsterNameIndex;
	int MonsterHp;
	int MonsterAttack;
	string RecentMonsterName; // 직전에 전투한 몬스터 이름
	bool SameWithRecentMonsterName; // 직전 몬스터와 같은 이름이 나오지 않도록

public:

	Monster(int plLevel);

	string GetMonsterName() { return MonsterName; }
	void SetMonsterName(string name) { MonsterName = name; }

	int GetMonsterNameIndex() { return MonsterNameIndex; }
	void SetMonsetNameIndex(int index) { MonsterNameIndex = index; }
	// 생성자에서 규칙에 의해 설정되는데 세터 필요?

	int GetMonsterHp() { return MonsterHp; }
	void SetMonsterHp(int hp) { MonsterHp = hp; } // 필요?
	
	int GetMonsterAttack() { return MonsterAttack; }
	void SetMonsterAttack(int attack) { MonsterAttack = attack; }

	int TakeDamage(int damage);

	string PrintMonsterStatus();
};
