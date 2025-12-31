#include <cstdlib>
#include "Database.h"
#include "Monster.h"

using namespace std;

Monster::Monster(int plLevel, string RecentMonsterName) {
	
	// 직전 몬스터이름을 저장해서 해당 몬스터 이름과 같으면 다시 뽑기
	bool SameWithRecentMonsterName; // 여기서만 쓰니까 굳이 멤버함수로 정의할 필요가 없음
	do {
		int randSize = rand() % monsterNames.size();
		MonsterNameIndex = randSize;
		MonsterName = monsterNames[MonsterNameIndex]; // 랜덤 몬스터 생성

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
		RecentMonsterName = MonsterName;

		return MonsterHp;
	}

	return MonsterHp;
}

string Monster::PrintMonsterStatus() {
	string ReturnString = "";
	ReturnString += "몬스터 " + MonsterName + "등장!\n";
	ReturnString += "현재 체력: " + to_string(MonsterHp) + "\n";
	ReturnString += "공격력: " + to_string(MonsterAttack) + "\n";

	return ReturnString;
}
