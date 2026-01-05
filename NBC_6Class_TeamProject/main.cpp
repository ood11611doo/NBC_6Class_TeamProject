#include <Windows.h>
#include <iostream>
#include "GameManager.h"
#include "StreamManager.h"
#include "Database.h"

using namespace std;

BattleType BattlePrint(string plName) {
    StreamManager::ClearScreen();
    int plLevelBefore = GameManager::Get().GetPlayerLevel();
    GameManager::Get().CreateMonster();
    string monsterName = GameManager::Get().GetMonsterName();
    cout << GameManager::Get().GetMonsterGen() << endl;
    bool battleResult = GameManager::Get().StartBattle();

    cout << StreamManager::PrintText_BattleLog(plName, monsterName, GameManager::Get().GetBattleLog()) << endl;

    if (battleResult) {
        if (GameManager::Get().GetPlayerLevel() >= PLAYER_MAX_LVL) {
            if (GameManager::Get().GetPlayerLevel() == plLevelBefore) {
                return BattleType::bossDefeated;
            } else {
                cout << StreamManager::PrintText_BossAppeared() << endl;
            }
        }

        cout << StreamManager::PrintText_BattleRewards(plName, *GameManager::Get().GetBattleRewards()) << endl;
        cout << GameManager::Get().PrintPlayerEXPAndGold() << endl << endl;
        GameManager::Get().AfterBattle();

        return BattleType::playerWin;
    }

    return BattleType::gameOver;
}

void ShopPrint() {
    cout << StreamManager::PrintText_ViewShopSelection();

    int choiceCheck;
    cin >> choiceCheck;

    switch (choiceCheck) {
    default:
        break;
    case 0:
        break;

    case 1: {
        int cinGet;
        cout << StreamManager::PrintText_ViewShopBuy();
    }
        break;
    case 2: {
        int cinGet;

    }
        break;
    }

    StreamManager::ClearScreen();
}

int main() {
    SetConsoleOutputCP(65001);

    cout << StreamManager::PrintText_InputName();
    string playerName = StreamManager::GetUTF8Input();
    GameManager::Get().SetPlayerName(playerName);
    cout << StreamManager::PrintText_PlayerCreated(playerName) << endl << endl;
    cout << GameManager::Get().PrintPlayerStatus() << endl;
    StreamManager::WaitForEnter();

    bool gameExitCheck = false;
    BattleType battleResult = BattlePrint(playerName);

    while (!gameExitCheck) {
        if (battleResult == BattleType::gameOver) {
            cout << StreamManager::PrintText_GameOver(playerName) << endl;
            break;
        } else if (battleResult == BattleType::bossDefeated) {
            cout << StreamManager::PrintText_BossDefeated() << endl;
            break;
        }

        cout << StreamManager::PrintText_ViewSelection() << endl;
        cout << StreamManager::PrintText_InputSelection();

        int choiceCheck;
        cin >> choiceCheck;
        
        switch (choiceCheck) {
        case 1:
            StreamManager::ClearScreen();
            battleResult = BattlePrint(playerName);
            break;
        case 2:
            StreamManager::ClearScreen();
            ShopPrint();
            break;
        case 8:
            StreamManager::ClearScreen();
            cout << GameManager::Get().PrintPlayerStatus() << endl;
            break;
        case 9:
            StreamManager::ClearScreen();
            cout << GameManager::Get().GetKillLog() << endl;
            break;
        case 0:
            cout << StreamManager::PrintText_QuitGame() << endl;
            gameExitCheck = true;
            break;
        default:
            cout << StreamManager::PrintText_WrongSelection() << endl << endl;
            break;
        }
    }

	return 0;
}
