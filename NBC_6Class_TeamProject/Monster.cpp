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
// Todo : 기존 생성자에서 bool값 추가된 생성자
// bool값 사용목적 - 생성되는 몬스터가 보스인지 아닌지를 판단
// 보스면은 생성할 때 기존 랜덤 생성범위의 1.5배 사이에서 생성하도록

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

// Todo : 기본 몬스터로 생성된 상태에서, 보스 몬스터 스탯으로 전환하는 함수
// 함수 이름 : SetMonsterToBoss
// 기존 스탯에서 1.5배를 할 지, 스탯을 1.5배 다시 생성할지에 따라
// player level을 받아오는 부분을 넣거나, 넣지 않으셔도 됩니다
