#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
    player = new Player();
    battleSystem = new BattleSystem();
    logSystem = new LogSystem();
}
GameManager::~GameManager() {
    delete player;
    delete battleSystem;
    delete logSystem;
}

string GameManager::GetMonsterName() {
    if (battleSystem->GetMonster() != nullptr)
        return battleSystem->GetMonster()->GetMonsterName();

    return "";
}
string GameManager::GetMonsterGen() {
    if (battleSystem->GetMonster() != nullptr)
        return battleSystem->GetMonster()->PrintMonsterStatus();

    return "";
}

bool GameManager::StartBattle() {
    bool battleResult = battleSystem->Battle(player);
    if (battleResult) {
        logSystem->AddKill(battleSystem->GetMonster()->GetMonsterName());
    }

    return battleResult;
}

void GameManager::AfterBattle() {
    battleSystem->DeleteMonster();
    battleSystem->ClearLog();
}
