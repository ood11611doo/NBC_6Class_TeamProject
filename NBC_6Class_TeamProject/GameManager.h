#pragma once
#include "Player.h"
#include "Monster.h"
#include "BattleSystem.h"
#include "LogSystem.h"
#include "Database.h"

using namespace std;

class GameManager {
private:
    GameManager();
    ~GameManager();

    Player* player;
    BattleSystem* battleSystem;
    LogSystem* logSystem;

public:
    static GameManager& Get() {
        static GameManager instance;
        return instance;
    }

    // Try not to use this directly
    Player* GetPlayer() { return player; }
    BattleSystem* GetBattleSystem() { return battleSystem; }
    LogSystem* GetLogSystem() { return logSystem; }

    void SetPlayerName(string name);
    string GetPlayerName() { return player->getName(); }
    string ViewPlayerStatus();
    string ViewPlayerEXPAndGold() { return player->PrintEXPAndGold(); }
    string GetPlayerItemName(int itemIndex) { return player->GetItemName(itemIndex); }

    void CreateMonster();
    string GetMonsterName();
    string GetMonsterGen();

    bool StartBattle();
    const vector<BattleRecord*> GetBattleLog() { return battleSystem->GetBattleRecords(); }
    const int GetExpReward() { return battleSystem->GetExpReward(); }
    const int GetGoldReward() { return battleSystem->GetGoldReward(); }
    const int GetItemReward() { return battleSystem->GetItemReward(); }
    void AfterBattle();
};
