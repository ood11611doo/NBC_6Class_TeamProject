#pragma once
#include <string>
#include "Player.h"
#include "Monster.h"

class BattleSystem {
private:
	Monster* monster_;
	std::string recentMonsterName;
	vector<BattleRecord*> battleRecords;
	BattleReward* battleReward;

public:
	BattleSystem();
	~BattleSystem();

	Monster* GetMonster() { return monster_; }
	const vector<BattleRecord*> GetBattleRecords() { return battleRecords; }
	const BattleReward* GetBattleReward() { return battleReward; }

	void GenerateMonster(int plLevel);
	bool Battle(Player* pl); // 전투: true=플레이어 승리, false=플레이어 패배
	void DeleteMonster();
	void ClearLog();
};
