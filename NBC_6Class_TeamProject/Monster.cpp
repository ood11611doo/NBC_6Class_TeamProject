#include <cstdlib>
#include <iostream> // 메시지 출력을 위해 추가
#include "Database.h"
#include "Monster.h"

using namespace std;

// 1. 일반 생성자
Monster::Monster(int plLevel, std::string RecentMonsterName) : isBossMonster(false) {
	bool SameWithRecentMonsterName;
	do {
		int randSize = rand() % monsterNames.size();
		MonsterName = monsterNames[randSize];
		SameWithRecentMonsterName = (MonsterName == RecentMonsterName);
	} while (SameWithRecentMonsterName);

	int RandomValueHp = rand() % (11) + 20; // 20~30
	MonsterHp = plLevel * RandomValueHp;
	int RandomValueAttack = rand() % (6) + 5; // 5~10
	MonsterAttack = plLevel * RandomValueAttack;
}

// 2. Todo: 보스 여부에 따른 생성자 (가이드 반영)
Monster::Monster(int plLevel, std::string RecentMonsterName, bool isBoss) : isBossMonster(isBoss) {
	if (isBoss) {
		// 보스 전용 이름 선택
		int randSize = rand() % bossNames.size();
		MonsterName = bossNames[randSize];
		// 보스 전용 스탯 설정
		SetMonsterToBoss(plLevel);
	}
	else {
		// 일반 몬스터 로직 (위 생성자와 동일하게 구현)
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

// 3. Todo: 보스 스탯 전환 함수 (가이드: 1.5배 범위)
void Monster::SetMonsterToBoss(int plLevel) {
	isBossMonster = true;

	// 기존 범위(20~30, 5~10)의 1.5배를 적용합니다.
	// HP: 30~45 범위 / ATK: 8~15 범위
	int BossHpRange = rand() % 16 + 30;
	MonsterHp = plLevel * BossHpRange;

	int BossAtkRange = rand() % 8 + 8;
	MonsterAttack = plLevel * BossAtkRange;

	// 보스 등장 연출용 태그
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
