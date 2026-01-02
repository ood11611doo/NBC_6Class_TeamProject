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
	// Todo : 기존 생성자에서 bool값 추가된 생성자
	// bool값 사용목적 - 생성되는 몬스터가 보스인지 아닌지를 판단
	// 보스면은 생성할 때 기존 랜덤 생성범위의 1.5배 사이에서 생성하도록

	std::string GetMonsterName() { return MonsterName; }
	void SetMonsterName(std::string name) { MonsterName = name; }

	int GetMonsterHp() { return MonsterHp; }
	void SetMonsterHp(int hp) { MonsterHp = hp; } // 필요?
	
	int GetMonsterAttack() { return MonsterAttack; }
	void SetMonsterAttack(int attack) { MonsterAttack = attack; }

	int TakeDamage(int damage);
	std::string PrintMonsterStatus();

	// Todo : 기본 몬스터로 생성된 상태에서, 보스 몬스터 스탯으로 전환하는 함수
	// 함수 이름 : SetMonsterToBoss
	// 기존 스탯에서 1.5배를 할 지, 스탯을 1.5배 다시 생성할지에 따라
	// player level을 받아오는 부분을 넣거나, 넣지 않으셔도 됩니다
};
