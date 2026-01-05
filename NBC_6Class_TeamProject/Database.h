#pragma once
#include <string>
#include <vector>

using namespace std;

// ----- Screen debug related -----
constexpr const char* ANSI_CURSOR_HOME = "\033[H";
constexpr const char* ANSI_CLEAR_SCREEN = "\033[J";

// ----- Player related values -----
constexpr const int PLAYER_MAX_LVL = 10;
constexpr const int PLAYER_MAX_EXP = 100;

constexpr const int PLAYER_START_LVL = 1;
constexpr const int PLAYER_START_HEALTH = 200;
constexpr const int PLAYER_START_ATTACK = 30;

constexpr const int PLAYER_LVLUP_HEALTH_MUL = 20;
constexpr const int PLAYER_LVLUP_ATTACK_MUL = 5;

constexpr const int PLAYER_POTION_ATTACK_CHANCE = 25;
constexpr const int PLAYER_POTION_HEALTH_PERCENT = 50;
constexpr const int PLAYER_POTION_HEALTH_CHANCE = 75;

// ----- Monster related values -----
constexpr const int MONSTER_HEALTH_MUL_MIN = 20;
constexpr const int MONSTER_ATTACK_MUL_MIN = 5;

constexpr const int MONSTER_HEALTH_MUL_MAX = 30;
constexpr const int MONSTER_ATTACK_MUL_MAX = 10;

constexpr const int MONSTER_REWARD_EXP = 50;
constexpr const int MONSTER_REWARD_GOLD_MIN = 10;
constexpr const int MONSTER_REWARD_GOLD_MAX = 20;
constexpr const int MONSTER_REWARD_ITEM_CHANCE = 30;

// ----- Item related values -----
constexpr const char* ITEM_HEALING_NAME = "회복 물약";
constexpr const int ITEM_HEALING_PRICE = 20;
constexpr const int ITEM_HEALING_VALUE = 50;

constexpr const char* ITEM_BUFFDAMAGE_NAME = "공격력 강화 물약";
constexpr const int ITEM_BUFFDAMAGE_PRICE = 30;
constexpr const int ITEM_BUFFDAMAGE_VALUE = 10;

constexpr const float ITEM_SELL_PRICE_RATIO = 0.6f;

inline int GetBasicPrice(int index) {
	switch (index) {
	case 0:
		return ITEM_HEALING_PRICE;
	case 1:
		return ITEM_BUFFDAMAGE_PRICE;
	}

	return 0;
}

inline int GetCellPrice(int index) {
	return GetBasicPrice(index) * ITEM_SELL_PRICE_RATIO;
}

enum RecordType {
	playerAttack,
	playerHeal,
	playerBuff,
	monsterAttack
};
enum BattleType {
	playerWin,
	bossDefeated,
	gameOver
};

struct BattleRecord {
	RecordType recType;
	int data;
};
struct BattleReward {
	int exp;
	int gold;
	int itemIndex;
};

const vector<string> monsterNames = {
	"고블린",
	"독거미",
	"스켈레톤",
	"슬라임",
	"오크",
	"코볼트"
};

const vector<string> bossNames = {
	"홉고블린",
	"오크 제너럴",
	"보스 몬스터임"
};