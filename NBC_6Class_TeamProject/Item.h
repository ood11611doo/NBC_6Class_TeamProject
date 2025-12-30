#pragma once
#include <string>

class Player;

using namespace std;

class Item {
	// 아이템들(자식)의 갯수는 랜덤하게 Player 클래스의 아이템자료형 백터에 쌓일 것
	// 따라서 따로 갯수를 멤버변수로 선언해 가져오거나 수정할 필요없이 
	// use함수에서 Player의 Item 멤버변수의 배열에 find()로 사용하려는 아이템이 있는지 체크 후 사용
public:
	// 어차피 자식클래스들에서 멤버변수와 함수를 각자 다르게 할 예정
	// 가상함수 선언 + 소멸자만 선언
	// GetName()
	virtual string GetName() const = 0;
	// Use(Character* pl)
	virtual void Use(Player* InPlayer) = 0;
	// 소멸자
	virtual ~Item() = default;
};
