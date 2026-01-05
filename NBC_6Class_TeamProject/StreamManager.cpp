#include <sstream>
#include "StreamManager.h"

using namespace std;

void StreamManager::WaitForEnter() {
    cout << "계속하려면 Enter 키를 누르세요..." << endl;
    cin.clear();
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
    cin.get();
}
string StreamManager::GetUTF8Input() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    wchar_t wbuffer[1024];
    DWORD charactersRead = 0;
    if (!ReadConsoleW(hInput, wbuffer, 1024, &charactersRead, NULL)) {
        return "";
    }
    wstring wstr(wbuffer, charactersRead);
    while (!wstr.empty() && (wstr.back() == L'\r' || wstr.back() == L'\n')) {
        wstr.pop_back();
    }
    if (wstr.empty()) return "";
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), static_cast<int>(wstr.size()), NULL, 0, NULL, NULL);
    string utf8Str(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), static_cast<int>(wstr.size()), &utf8Str[0], size_needed, NULL, NULL);
    return utf8Str;
}

string StreamManager::PrintText_InputName() {
    return "캐릭터 이름을 입력하세요: ";
}
string StreamManager::PrintText_InputSelection(bool isCounting) {
    return isCounting ? "입력: " : "선택: ";
}
string StreamManager::PrintText_ViewSelection() {
    stringstream ss;
    ss << "1. 다음 스테이지로" << endl;
    ss << "2. 상점 진입" << endl;
    ss << "8. 플레이어 정보 확인" << endl;
    ss << "9. 킬로그 확인" << endl;
    ss << "0. 게임 종료" << endl;
    return ss.str();
}
string StreamManager::PrintText_ViewShopSelection() {
    stringstream ss;
    ss << "==== 상점에 진입했습니다 ====" << endl;
    ss << "1. 아이템 구매" << endl;
    ss << "2. 아이템 판매" << endl;
    ss << "0. 돌아가기" << endl;
    return ss.str();
}
string StreamManager::PrintText_ViewShopBuy() {
    stringstream ss;
    ss << "---- 아이템 구매 ----" << endl;
    ss << "1. " << ITEM_HEALING_NAME << endl;
    ss << "2. " << ITEM_BUFFDAMAGE_NAME << endl;
    ss << "0. 돌아가기" << endl;
    return ss.str();
}
string StreamManager::PrintText_ViewShopCount(bool isBuy) {
    string nameCheck = isBuy ? "구매" : "판매";
    return "---- 아이템 " + nameCheck + " 수량 입력 ----";
}
string StreamManager::PrintText_ViewShopIsSuccess(bool isBuy, bool isSuccess) {
    stringstream ss;
    string nameCheck = isBuy ? "구매" : "판매";
    string successCheck = isSuccess ? "성공" : "실패";
    ss << "아이템 " << nameCheck << "에 " << successCheck << "했습니다.";
    return ss.str();
}
string StreamManager::PrintText_WrongSelection() {
    return "올바른 선택지가 아닙니다. 다시 입력해주세요.";
}
string StreamManager::PrintText_BossAppeared() {
    stringstream ss;
    ss << "- 10레벨을 달성했다! -" << endl;
    ss << "- 이제 일반 몬스터는 상대도 안 된다! -" << endl;
    return ss.str();
}
string StreamManager::PrintText_QuitGame() {
    return "게임을 종료합니다.";
}
string StreamManager::PrintText_BossDefeated() {
    stringstream ss;
    ss << "- asdf -" << endl;
    return ss.str();
}

string StreamManager::PrintText_PlayerCreated(const string& name) {
    return "캐릭터 " + name + " 생성 완료!";
}
string StreamManager::PrintText_GameOver(const string& name) {
    return name + "가 사망했습니다. 게임 오버!";
}

string StreamManager::PrintText_ViewShopSell(const std::vector<Item*> items) {
    stringstream ss;
    ss << "---- 아이템 판매 ----" << endl;
    if (items[0] != nullptr && items[0]->GetCount() > 0) {
        ss << "1. " << ITEM_HEALING_NAME << endl;
    }
    if (items[1] != nullptr && items[1]->GetCount() > 0) {
        ss << "2. " << ITEM_BUFFDAMAGE_NAME << endl;
    }
    ss << "0. 돌아가기" << endl;
    return ss.str();
}

string StreamManager::PrintText_BattleLog(const string& plName, const string& monName, const std::vector<BattleRecord*>& records) {
    stringstream ss;
    for (const auto& record : records) {
        switch (record->recType) {
        case RecordType::playerAttack:
            if (record->data > 0) {
                ss << plName << "가 " << monName << "을 공격합니다! " << monName << " 체력: " << record->data << endl;
            } else {
                ss << plName << "가 " << monName << "을 공격합니다! " << monName << " 처치!" << endl;
            }
            break;
        case RecordType::playerHeal:
            ss << plName << "가 회복 물약을 사용했습니다! 현재 체력: " << record->data << endl;
            break;
        case RecordType::playerBuff:
            ss << plName << "가 공격력 강화 물약을 사용했습니다! 현재 공격력: " << record->data << endl;
            break;
        case RecordType::monsterAttack:
            ss << monName << "가 " << plName << "을 공격합니다! " << plName << " 체력: " << record->data << endl;
            break;
        default:
            break;
        }
    }
    return ss.str();
}
string StreamManager::PrintText_BattleRewards(const string& plName, const BattleReward& rewards) {
    stringstream ss;
    ss << plName << "가 " << rewards.exp << "EXP와 " << rewards.gold << " 골드를 획득했습니다." << endl;
    if (rewards.itemIndex >= 0) {
        string itemName;
        if (rewards.itemIndex == 0) {
            itemName = ITEM_HEALING_NAME;
        } else if (rewards.itemIndex == 1) {
            itemName = ITEM_BUFFDAMAGE_NAME;
        } else {
            itemName = "알 수 없는 아이템";
        }
        ss << plName << "가 " << itemName << " 아이템을 획득했습니다!" << endl;
    }
    return ss.str();
}