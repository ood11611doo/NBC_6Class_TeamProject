#include <sstream>
#include "LogSystem.h"

using namespace std;

string LogSystem::GetKillCount() {
	stringstream output;
	output << "몬스터 킬 로그\n";
	for (const auto& vals : killLog) {
		output << vals.first << ": " << vals.second << "\n";
	}
	return output.str();
}