#pragma once
#include <string>
#include <vector>

using namespace std;

// ----- Player related values -----
constexpr const int PLAYER_MAX_LVL = 10;
constexpr const int PLAYER_MAX_EXP = 100;

constexpr const int PLAYER_START_LVL = 1;
constexpr const int PLAYER_START_HEALTH = 200;
constexpr const int PLAYER_START_ATTACK = 30;

constexpr const int PLAYER_LVLUP_HEALTH_MUL = 20;
constexpr const int PLAYER_LVLUP_ATTACK_MUL = 5;

// ----- Monster related values -----
constexpr const int MONSTER_HEALTH_MUL_MIN = 20;
constexpr const int MONSTER_ATTACK_MUL_MIN = 5;

constexpr const int MONSTER_HEALTH_MUL_MAX = 30;
constexpr const int MONSTER_ATTACK_MUL_MAX = 10;

// ----- Item related values -----
constexpr const int ITEM_HEALING_VALUE = 50;
constexpr const int ITEM_BUFFDAMAGE_VALUE = 10;

const vector<string> monsterNames = {
	"고블린",
	"독거미",
	"스켈레톤",
	"슬라임",
	"오크",
	"코볼트"
};