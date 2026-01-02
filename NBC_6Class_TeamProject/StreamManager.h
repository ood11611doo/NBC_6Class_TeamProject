#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "Database.h"

class StreamManager {
public:
    // Screen related
    static void ClearScreen() { system("cls"); }

    // Input related
    static void WaitForEnter();
    static std::string GetUTF8Input();

    // Single calling without inputs
    static std::string PrintText_InputName();
    static std::string PrintText_InputSelection();
    static std::string PrintText_ViewSelection();
    static std::string PrintText_WrongSelection();
    static std::string PrintText_QuitGame();
    
    // Single calling with simple inputs
    static std::string PrintText_PlayerCreated(const string& name);
    static std::string PrintText_GameOver(const string& name);
    
    // Single calling with class or structs
    static std::string PrintText_BattleLog(const string& plName, const string& monName, const std::vector<BattleRecord*>& records);
    static std::string PrintText_BattleRewards(const string& plName, const BattleReward& rewards);
};

