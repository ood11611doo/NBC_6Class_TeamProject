#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Player {
private:
	//  vector - Item 클래스 배열값
	//  vector에 클래스 담을 때 포인터값으로 담아도 됨. 동적 할당용?
	string PlayerName = "";
	int PlayerLevel = 1;
	int PlayerMaxHealthPotion;
	int PlayerHealthPotion;
	int PlayerAttack;
	int Gold = 0;
	int PlayerExe = 0;
	vector<Item*> V = vector<Item*>(10, nullptr); // V[0] = new HealthPotion; // V[0].Use();

public:
	Player(string name) : PlayerMaxHp(200), PlayerHp(200), PlayerAttack(30), V(10, nullptr) // 포션과 부스터 주소 넣어주기
	{
		PlayerName = name;
	}
	
	~Player() {

	}
	// - Todo : getter, setter 함수 선언 필요
	// 이름 함수 (getter, setter)
	// 레벨 함수 (getter, setter)
	// 최대 체력 함수 (getter, setter)
	// 현재 체력 함수 (getter, setter)
	// 공격력 함수 (getter, setter)
	// 현재 경험치 함수 (getter, setter)
	// 현재 골드 함수 (getter, setter)
	// 현재 아이템 배열 함수 (getter)

	// 기능 함수 선언됨 - 자세한 내용 정의는 cpp파일로
	void CheckLevelUp();
	string PrintPlayerStatus();
	void UseItem(int itemIndex);
	int TakeDamage(int damage);
};
