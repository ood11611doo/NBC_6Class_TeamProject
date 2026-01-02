#include <cstdlib>
#include "Database.h"
#include "Monster.h"

Monster::Monster(int plLevel, std::string RecentMonsterName) {
	
	bool SameWithRecentMonsterName;
	do {
		int randSize = rand() % monsterNames.size();
		MonsterName = monsterNames[randSize];

		SameWithRecentMonsterName = false;

		if (MonsterName == RecentMonsterName) {
			SameWithRecentMonsterName = true;
		}

	} while (SameWithRecentMonsterName);

	int RandomValueHp = rand() % (11) + 20;
	MonsterHp = plLevel * RandomValueHp;
	int RandomValueAttack = rand() % (6) + 5;
	MonsterAttack = plLevel * RandomValueAttack;

}


int Monster::TakeDamage(int damage) {
	MonsterHp -= damage;
	
	if (MonsterHp <= 0) {
		MonsterHp = 0;
	}

	return MonsterHp;
}

std::string Monster::PrintMonsterStatus() {
	std::string ReturnString = "";
	ReturnString += "몬스터 " + MonsterName + "등장!\n";
	ReturnString += "현재 체력: " + to_string(MonsterHp) + "\n";
	ReturnString += "공격력: " + to_string(MonsterAttack) + "\n";

	return ReturnString;
}
