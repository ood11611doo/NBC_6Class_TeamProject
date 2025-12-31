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

void GameManager::SetPlayerName(string name) {
    player->setName(name);
}
string GameManager::ViewPlayerStatus() {
    return player->PrintPlayerStatus();
}

void GameManager::CreateMonster() {
    battleSystem->GenerateMonster(player->getLevel());
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
        // logSystem->AddKill(battleSystem->GetMonster()->GetNameIndex());
    }

    return battleResult;
}

void GameManager::AfterBattle() {
    battleSystem->DeleteMonster();
    battleSystem->ClearLog();
}
