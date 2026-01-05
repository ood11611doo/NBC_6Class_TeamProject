#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
    player = new Player();
    battleSystem = new BattleSystem();
    logSystem = new LogSystem();
    marketSystem = new MarketSystem();
}
GameManager::~GameManager() {
    delete player;
    delete battleSystem;
    delete logSystem;
    delete marketSystem;
}

void GameManager::CreateMonster() {
    battleSystem->GenerateMonster(player->getLevel());
    if (player->getLevel() >= PLAYER_MAX_LVL) {
        battleSystem->SetMonsterToBoss(player->getLevel());
    }
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

bool GameManager::TryBuyItem(int itemIndex_, int buyCount_) {
    return marketSystem->BuyItem(player, itemIndex_, buyCount_);
}

bool GameManager::TrySellItem(int itemIndex_, int sellCount_) {
    return marketSystem->SellItem(player, itemIndex_, sellCount_);
}
