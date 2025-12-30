#pragma once

using namespace std;

class Monster {
private:
	// - Todo : 변수 선언 필요
	// 
	// string 값 이름 변수
	// int값 몬스터 이름 가져온 인덱스
	// int값 현재 체력
	// int값 공격력

public:
	// - Todo : 생성자
	// int 플레이어 레벨값 기반으로 스탯이 설정되기 때문에
	// 아래 미리 선언되어있는 Monster값을 cpp파일에서 정의해주세요
	Monster(int plLevel);

	// - Todo : getter, setter 함수 선언 필요
	// 이름 함수 (getter, setter)
	// 이름 인덱스 함수 (getter, setter)
	// 현재 체력 함수 (getter, setter)
	// 공격력 함수 (getter, setter)

	// 기능 함수 선언됨 - 자세한 내용 정의는 cpp파일로
	int TakeDamage(int damage);
};
