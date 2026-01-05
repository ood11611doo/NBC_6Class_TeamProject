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
    bool isEscapeShop = false;
    
    while (!isEscapeShop) {
        cout << StreamManager::PrintText_ViewShopSelection();
        cout << StreamManager::PrintText_InputSelection();

        int choiceCheck;
        cin >> choiceCheck;

        switch (choiceCheck) {
        default:
            break;
        case 0:
            isEscapeShop = true;
            break;

        case 1: {
            int shopInnerGet;
            cout << endl;
            cout << StreamManager::PrintText_ViewShopBuy() << endl;
            cout << StreamManager::PrintText_InputSelection();
            cin >> shopInnerGet;
            switch (shopInnerGet)
            {
            default:
                break;
            case 0:
                StreamManager::ClearScreen();
                // 여기서 shopPrint() 부분이 재귀적으로 사용되면서 스택으로 쌓이기 때문에 0번을 두번입력해야 shop에서 완전 나올 수 있음
                //ShopPrint(); 주석처리로 지우기만 해도 어차피 스위치문 나가서 while문이 돌아가기 때문에 해결
                break;

            case 1:
            case 2:
                int realIndex = shopInnerGet - 1;
                cout << endl;
                cout << StreamManager::PrintText_ViewShopCount(true) << endl;
                cout << StreamManager::PrintText_InputSelection(true);
                int shopBuyCount;
                cin >> shopInnerGet;
                bool isSuccess = GameManager::Get().TryBuyItem(realIndex, shopInnerGet);
                cout << StreamManager::PrintText_ViewShopIsSuccess(true, isSuccess) << endl;
                isEscapeShop = isSuccess;
                StreamManager::WaitForEnter();
                break;
            }
        }
              break;
        case 2: {
            int shopInnerGet;
            vector<Item*> plItemGet = GameManager::Get().GetPlayerItems();
            cout << endl;
            cout << StreamManager::PrintText_ViewShopSell(plItemGet) << endl;
            cout << StreamManager::PrintText_InputSelection();
            cin >> shopInnerGet;
            switch (shopInnerGet)
            {
            default:
                break;
            case 0:
                StreamManager::ClearScreen();
                // ShopPrint(); 여기도 위와 같은 이유
                break;
            case 1:
            case 2:
                int realIndex = shopInnerGet - 1;
                if (plItemGet[realIndex] == nullptr) {
                    StreamManager::PrintText_WrongSelection();
                    break;
                }

                cout << endl;
                cout << StreamManager::PrintText_ViewShopCount(false) << endl;
                cout << StreamManager::PrintText_InputSelection(true);
                int shopBuyCount;
                cin >> shopInnerGet;
                bool isSuccess = GameManager::Get().TrySellItem(realIndex, shopInnerGet);
                cout << StreamManager::PrintText_ViewShopIsSuccess(false, isSuccess) << endl;
                isEscapeShop = isSuccess;
                StreamManager::WaitForEnter();
                break;
            }
        }
              break;
        }

        StreamManager::ClearScreen();
    }
}

int main() {
    SetConsoleOutputCP(65001);
    srand(time(nullptr));
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
