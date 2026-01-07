#include <cstdlib>
#include "Database.h"
#include "Monster.h"

using namespace std;

Monster::Monster(int plLevel, std::string RecentMonsterName) : isBossMonster(false) {
	bool SameWithRecentMonsterName;
	do {
		int randSize = rand() % monsterNames.size();
		MonsterName = monsterNames[randSize];
		SameWithRecentMonsterName = (MonsterName == RecentMonsterName);
	} while (SameWithRecentMonsterName);

	int RandomValueHp = rand() % (11) + 20;
	MonsterHp = plLevel * RandomValueHp;
	int RandomValueAttack = rand() % (6) + 5;
	MonsterAttack = plLevel * RandomValueAttack;
}
Monster::Monster(int plLevel, std::string RecentMonsterName, bool isBoss) : isBossMonster(isBoss) {
	if (isBoss) {
		int randSize = rand() % bossNames.size();
		MonsterName = bossNames[randSize];
		SetMonsterToBoss(plLevel);
	}
	else {
		bool SameWithRecentMonsterName;
		do {
			int randSize = rand() % monsterNames.size();
			MonsterName = monsterNames[randSize];
			SameWithRecentMonsterName = (MonsterName == RecentMonsterName);
		} while (SameWithRecentMonsterName);

		MonsterHp = plLevel * (rand() % 11 + 20);
		MonsterAttack = plLevel * (rand() % 6 + 5);
	}
}
void Monster::SetMonsterToBoss(int plLevel) {
	isBossMonster = true;

	int BossHpRange = rand() % 16 + 30;
	MonsterHp = plLevel * BossHpRange;

	int BossAtkRange = rand() % 8 + 8;
	MonsterAttack = plLevel * BossAtkRange;

	if (MonsterName.find("(BOSS)") == std::string::npos) {
		MonsterName = "[BOSS] " + MonsterName;
	}
}

int Monster::TakeDamage(int damage) {
	MonsterHp -= damage;
	if (MonsterHp <= 0) MonsterHp = 0;
	return MonsterHp;
}

std::string Monster::PrintMonsterStatus() {
	std::string ReturnString = "";
	ReturnString += "===============================\n";
	ReturnString += " 몬스터 " + MonsterName + " 가 나타났다!\n";
	ReturnString += " 현재 체력: " + to_string(MonsterHp) + "\n";
	ReturnString += " 공격력: " + to_string(MonsterAttack) + "\n";
	ReturnString += "===============================\n";
	return ReturnString;
}
