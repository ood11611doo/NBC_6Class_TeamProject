#pragma once
#include "Player.h"
#include "Monster.h"

using namespace std;

class BattleSystem {
private:
	Monster* monster_;

public:
	BattleSystem();
	~BattleSystem();

	// 기능 함수 선언됨 - 자세한 내용 정의는 cpp파일로
	void GenerateMonster(int plLevel); // 몬스터 생성
	bool Battle(Player* pl); // 전투: true=플레이어 승리, false=플레이어 패배
	void DeleteMonster(); // 몬스터 삭제
};
