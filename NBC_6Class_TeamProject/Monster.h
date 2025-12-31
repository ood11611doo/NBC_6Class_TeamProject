#pragma once
#include <random>
#include <string>

using namespace std;

class Monster {
private:
	string MonsterName;
	int MonsterNameIndex; // 나중에 질문

	int MonsterHp;
	int MonsterAttack;
	// string RecentMonsterName; // 객체 사라지면 같이 삭제됨 --> 배틀매니저
	// 둘내님 이거 매니저에 넣어주세요

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
