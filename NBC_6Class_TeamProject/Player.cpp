#include "Player.h"

using namespace std;

void Player::CheckLevelUp() {
	// - Todo : 기능 함수 정의 필요
	// 레벨업 계산 함수
	//  레벨업 함수 하나에서 경험치가 일정 이상인지 계산을 한 후에
	//  레벨업을 바로 실행시켜도 되고, 아니면 경험치 계산용 함수를
	//  새로 만들어도 됩니다.
}

string Player::PrintPlayerStatus() {
	// - Todo : 기능 함수 정의 필요
	// string 만들어서, 여기에 스탯 출력 메시지 반환해주시면 됩니다
	


	// 다 만든 후에 아래 더미 return값은 지우면 됨!
	return "";
}

void Player::UseItem(int itemIndex) {
	// - Todo : 기능 함수 정의 필요
	// 플레이어는 Item vector배열을 가지고 있음.
	// 여기서 itemIndex로, 어떤 아이템인지 종류를 받거나,
	// 아니면 배열 인덱스를 받거나 해서 해당 아이템을 없애는 것 까지는
	// 여기서 계산을 해줘야할듯?
	// Item에서 Use를 한 다음에 없애야함!
}

int Player::TakeDamage(int damage) {
	// - Todo : 기능 함수 정의 필요
	// 체력 감소를 해당 함수에서 진행
	// 그 후, 플레이어의 남은 체력을 return
	// 0 이하면 0으로 return



	// 다 만든 후에 아래 더미 return값은 지우면 됨!
	return 0;
}