#pragma once
#include "Player.h"
#include "Monster.h"

using namespace std;

class BattleSystem {
private:
	// - Todo : 변수 선언 필요
	// Monster 포인터 변수 - 함수에서 알아서 만들고 지우셈

public:
	// - Todo : 생성자 / 소멸자
	// - Todo : getter, setter

	// 기능 함수 선언됨 - 자세한 내용 정의는 cpp파일로
	void GenerateMonster(int plLevel);
	bool Battle(Player* pl);
	void DeleteMonster();
};
