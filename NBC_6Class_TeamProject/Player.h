#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Player {
private:
	// - Todo : 변수 선언 필요
	// 
	// string 값 이름 변수
	// int값 현재 레벨
	// int값 현재 체력 / 최대 체력
	// int값 공격력
	// int값 현재 경험치
	// int값 현재 골드
	// vector - Item 클래스 배열값
	//  vector에 클래스 담을 때 포인터값으로 담아도 됨. 동적 할당용?

public:
	// - Todo : 생성자
	// 값 입력 받아서 만들어도 되지만
	// 그럴 경우 기본 생성자도 만들어서 2종류 만들어주세요

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
