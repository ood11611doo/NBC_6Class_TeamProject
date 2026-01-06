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
    bool isWrongSelection = false;
    bool isEscapeShop = false;

    while (!isEscapeShop) {
        cout << StreamManager::PrintText_ViewShopSelection();
        if (isWrongSelection) {
            isWrongSelection = false;
            cout << StreamManager::PrintText_WrongSelection() << endl;
        }
        cout << StreamManager::PrintText_InputSelection();

        int choiceCheck = StreamManager::GetIntegerInput();

        switch (choiceCheck) {
        default:
            isWrongSelection = true;
            break;
        case 0:
            isEscapeShop = true;
            break;

        case 1: {
            cout << endl;
            cout << StreamManager::PrintText_ViewShopBuy() << endl;
            cout << StreamManager::PrintText_InputSelection();
            int shopInnerGet = StreamManager::GetIntegerInput();
            switch (shopInnerGet)
            {
            default:
                isWrongSelection = true;
                break;
            case 0:
                StreamManager::ClearScreen();
                break;

            case 1:
            case 2:
                int realIndex = shopInnerGet - 1;
                cout << endl;
                cout << StreamManager::PrintText_ViewShopCount(true) << endl;
                cout << StreamManager::PrintText_ViewPlayerGold(GameManager::Get().GetPlayerGold()) << endl;
                cout << StreamManager::PrintText_ViewItemPrice(GetBasicPrice(realIndex)) << endl;
                cout << StreamManager::PrintText_InputSelection(true);
                int shopBuyCount = StreamManager::GetIntegerInput();
                if (shopBuyCount <= 0) {
                    isWrongSelection = true;
                    break;
                }
                bool isSuccess = GameManager::Get().TryBuyItem(realIndex, shopBuyCount);
                cout << StreamManager::PrintText_ViewShopIsSuccess(true, isSuccess) << endl;
                isEscapeShop = isSuccess;
                StreamManager::WaitForEnter();
                break;
            }
        }
              break;
        case 2: {
            vector<Item*> plItemGet = GameManager::Get().GetPlayerItems();
            cout << endl;
            cout << StreamManager::PrintText_ViewShopSell(plItemGet) << endl;
            cout << StreamManager::PrintText_InputSelection();
            int shopInnerGet = StreamManager::GetIntegerInput();
            switch (shopInnerGet)
            {
            default:
                isWrongSelection = true;
                break;
            case 0:
                StreamManager::ClearScreen();
                break;
            case 1:
            case 2:
                int realIndex = shopInnerGet - 1;
                if (plItemGet[realIndex] == nullptr || plItemGet[realIndex] ->GetCount() <= 0) {
                    isWrongSelection = true;
                    break;
                }

                cout << endl;
                cout << StreamManager::PrintText_ViewShopCount(false) << endl;
                cout << StreamManager::PrintText_ViewItemCount(plItemGet[realIndex]->GetName(), plItemGet[realIndex]->GetCount()) << endl;
                cout << StreamManager::PrintText_InputSelection(true);
                int shopSellCount = StreamManager::GetIntegerInput();
                if (shopSellCount <= 0) {
                    isWrongSelection = true;
                    break;
                }
                bool isSuccess = GameManager::Get().TrySellItem(realIndex, shopSellCount);
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
    srand(static_cast<unsigned int>(std::time(nullptr)));

    cout << StreamManager::PrintText_InputName();
    string playerName = StreamManager::GetUTF8Input();
    GameManager::Get().SetPlayerName(playerName);
    cout << StreamManager::PrintText_PlayerCreated(playerName) << endl << endl;
    cout << GameManager::Get().PrintPlayerStatus() << endl;
    StreamManager::WaitForEnter();
    
    bool isWrongSelection = false;
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
        if (isWrongSelection) {
            isWrongSelection = false;
            cout << StreamManager::PrintText_WrongSelection() << endl;
        }
        cout << StreamManager::PrintText_InputSelection();

        int choiceCheck = StreamManager::GetIntegerInput();
        
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
            StreamManager::ClearScreen();
            isWrongSelection = true;
            break;
        }
    }

    StreamManager::WaitForEnter();

	return 0;
}
