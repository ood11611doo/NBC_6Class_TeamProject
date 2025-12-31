#include "Player.h"

using namespace std;

void Player::CheckLevelUp() {
	PlayerExe += 50;

	if (PlayerExe >= 100) {
		PlayerExe -= 100;
		PlayerLevel += 1;
		PlayerMaxHealthPotuin += PlayerLevel * 20;
		PlayerHealthPotion = PlayerMaxHealthPotion;
		PlayerAttack += PlayerLevel * 5;
	}
}

string Player::PrintPlayerStatus() {
	string PlayerStatus;
	PlayerStatus += "이름: " + PlayerName + "\n";
	PlayerStatus += "레벨: " + PlayerLevel + "\n";
	PlayerStatus += "최대 체력: " + PlayerMaxHealthPotion + "\n";
	PlayerStatus += "현재 체력: " + PlayerHealthPotuin + "\n";
	PlayerStatus += "공격력: " + PlayerAttack + "\n";
	PlayerStatus += "골드: " + Gold + "\n";
	PlayerStatus += "경험치: " + PlayerExe + "/100" + "\n";
	
	return PlayerStatus;
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

	if (PlayerHp > 0) {
		PlayerHp -= damage;
	}
	else if (PlayerHp <= 0) {
		PlayerHp = 0;
		retuen 0;
	}
	return PlayerHp;
}