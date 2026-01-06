#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "Database.h"
#include "Item.h"

class StreamManager {
public:
    // Screen related
    static void ClearScreen() { system("cls"); }

    // Input related
    static void WaitForEnter();
    static std::string GetUTF8Input();
    static int GetIntegerInput();

    // Single calling without inputs
    static std::string PrintText_InputName();
    static std::string PrintText_ViewSelection();
    static std::string PrintText_ViewShopSelection();
    static std::string PrintText_ViewShopBuy();
    static std::string PrintText_WrongSelection();
    static std::string PrintText_BossAppeared();
    static std::string PrintText_QuitGame();
    static std::string PrintText_BossDefeated();
    
    // Single calling with simple inputs
    static std::string PrintText_PlayerCreated(const std::string& name);
    static std::string PrintText_GameOver(const std::string& name);
    static std::string PrintText_InputSelection(bool isCounting = false);
    static std::string PrintText_ViewShopCount(bool isBuy);
    static std::string PrintText_ViewShopIsSuccess(bool isBuy, bool isSuccess);
    static std::string PrintText_ViewPlayerGold(int curGold);
    static std::string PrintText_ViewItemPrice(int price);
    static std::string PrintText_ViewItemCount(const std::string& name, int count);
    
    // Single calling with class or structs
    static std::string PrintText_ViewShopSell(const std::vector<Item*> items);
    static std::string PrintText_BattleLog(const std::string& plName, const std::string& monName, const std::vector<BattleRecord*>& records);
    static std::string PrintText_BattleRewards(const std::string& plName, const BattleReward& rewards);
};

