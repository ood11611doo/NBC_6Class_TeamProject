#include <cstdlib>
#include "Database.h"
#include "Monster.h"

using namespace std;

Monster::Monster(int plLevel) {
	// - Todo : 생성자 정의 필요
// 몬스터 스탯 설정 필요
//  생성할 때 플레이어 레벨 기반으로 스탯 설정이 되기 때문에
// 플레이어 레벨값을 무조건 받아서 몬스터를 생성하는 식이 필요
// int randSize = rand() % monsterNames.size();
// ㄴ이 위 식이 vector 랜덤 인덱스를 뽑아주니, 그걸로 사용하면 됨

	do {
		int randSize = rand() % monsterNames.size();
		MonsterNameIndex = randSize;
		MonsterName = monsterNames[randSize]; // 랜덤 몬스터 생성
		SameMonsterName = false;

		for (const string& monsterName : KilledMonsterList) {
			if (MonsterName == monsterName) {
				SameMonsterName = true;
				break;
			}
		}
	} while (SameMonsterName); 
	
	/*if (string monsterName : KilledMonsterList) {
		monsterName == MonsterName;
	}
	KilledMonsterList.push_back(MonsterName);
	*/

	// 이미 처치한 몬스터 중복 소환 방지 필요함.

	int RandomValueHp = rand() % (11) + 20;
	MonsterHp = plLevel * RandomValueHp;
	int RandomValueAttack = rand() % (6) + 5;
	MonsterAttack = plLevel * RandomValueAttack;

}


int Monster::TakeDamage(int damage) {
	// - Todo : 기능 함수 정의 필요
	// 체력 감소를 해당 함수에서 진행
	// 그 후, 몬스터의 남은 체력을 return
	// 0 이하면 0으로 return
	MonsterHp -= damage;
	
	if (MonsterHp <= 0) {
		MonsterHp = 0;

		KilledMonsterList.push_back(MonsterName);
		return MonsterHp;
	} // 몬스터 죽음 -> 여기에 구현?

	return MonsterHp;
}
