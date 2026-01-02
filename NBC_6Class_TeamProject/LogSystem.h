#pragma once
#include <map>
#include <string>

using namespace std;

class LogSystem {
private:
	map<std::string, int> killLog;

public:
	void AddKill(std::string monsterIndex) { killLog[monsterIndex]++; }
	std::string GetKillCount();
};
