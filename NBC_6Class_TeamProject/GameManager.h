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
    // C++ Singleton
    static GameManager& Get() {
        static GameManager instance;
        return instance;
    }

    // Try not to use this directly
    Player* GetPlayer() { return player; }
    BattleSystem* GetBattleSystem() { return battleSystem; }
    LogSystem* GetLogSystem() { return logSystem; }

    void SetPlayerName(string name) { player->setName(name); }
    string GetPlayerName() { return player->getName(); }
    string PrintPlayerStatus() { return player->PrintPlayerStatus(); }
    string PrintPlayerEXPAndGold() { return player->PrintEXPAndGold(); }
    string GetPlayerItemName(int itemIndex) { return player->GetItemName(itemIndex); }

    void CreateMonster() { battleSystem->GenerateMonster(player->getLevel()); }
    string GetMonsterName();
    string GetMonsterGen();
    string GetKillLog() { return logSystem->GetKillCount(); }

    bool StartBattle();
    const vector<BattleRecord*> GetBattleLog() { return battleSystem->GetBattleRecords(); }
    const BattleReward* GetBattleRewards() { return battleSystem->GetBattleReward(); }
    void AfterBattle();
};
