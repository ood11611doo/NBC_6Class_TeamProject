#pragma once
#include <random>
#include <string>

// 몬스터의 
class Monster {   // 함수는 대문자 시작, 변수는 소문자 시작
private:
	std::string MonsterName;
	int MonsterNameIndex; // 나중에 질문
	int MonsterHp;
	int MonsterAttack;
	// string RecentMonsterName; // 객체 사라지면 같이 삭제됨 --> 배틀매니저
	// 둘내님 이거 매니저에 넣어주세요

public:

	Monster(int plLevel, std::string RecnetMonsterName);

	std::string GetMonsterName() { return MonsterName; }
	void SetMonsterName(std::string name) { MonsterName = name; }

	int GetMonsterNameIndex() { return MonsterNameIndex; }
	void SetMonsetNameIndex(int index) { MonsterNameIndex = index; }

	int GetMonsterHp() { return MonsterHp; }
	void SetMonsterHp(int hp) { MonsterHp = hp; } // 필요?
	
	int GetMonsterAttack() { return MonsterAttack; }
	void SetMonsterAttack(int attack) { MonsterAttack = attack; }

	int TakeDamage(int damage);

	std::string PrintMonsterStatus();
};
