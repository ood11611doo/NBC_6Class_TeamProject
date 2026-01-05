#include <Windows.h>
#include <iostream>
#include "GameManager.h"
#include "StreamManager.h"
#include "Database.h"

using namespace std;

bool BattlePrint(string plName) {
    StreamManager::ClearScreen();
    GameManager::Get().CreateMonster();
    string monsterName = GameManager::Get().GetMonsterName();
    cout << GameManager::Get().GetMonsterGen() << endl;
    bool battleResult = GameManager::Get().StartBattle();

    cout << StreamManager::PrintText_BattleLog(plName, monsterName, GameManager::Get().GetBattleLog()) << endl;

    if (battleResult) {
        cout << StreamManager::PrintText_BattleRewards(plName, *GameManager::Get().GetBattleRewards()) << endl;
        cout << GameManager::Get().PrintPlayerEXPAndGold() << endl << endl;
        GameManager::Get().AfterBattle();
    }

    return battleResult;
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
    bool battleResult = BattlePrint(playerName);

    while (!gameExitCheck) {
        if (!battleResult) {
            cout << StreamManager::PrintText_GameOver(playerName) << endl;
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
