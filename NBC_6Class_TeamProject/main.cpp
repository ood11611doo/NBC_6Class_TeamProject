#include <Windows.h>
#include <iostream>
#include "GameManager.h"
#include "Database.h"

using namespace std;

void GetEnterInput() {
    cin.clear();
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
    cin.get();
}
string GetUTFInput() {
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

int main() {
    SetConsoleOutputCP(65001);

    cout << "캐릭터 이름을 입력하세요: ";
    string playerName = GetUTFInput();
    GameManager::Get().SetPlayerName(playerName);
    cout << "캐릭터 " << playerName << " 생성 완료!" << endl;
    cout << GameManager::Get().ViewPlayerStatus() << endl;
    cout << "계속하려면 Enter 키를 누르세요..." << endl;
    GetEnterInput();

    while (true) {
        Sleep(500);
        system("cls");
        GameManager::Get().CreateMonster();
        string monsterName = GameManager::Get().GetMonsterName();
        cout << GameManager::Get().GetMonsterGen() << endl;
        bool battleResult = GameManager::Get().StartBattle();

        for (const auto& record : GameManager::Get().GetBattleLog()) {
            switch (record->recType) {
            case RecordType::playerAttack:
                if (record->data > 0) {
                    cout << playerName << "가 " << monsterName << "을 공격합니다! " << monsterName << " 체력: " << record->data << endl;
                }
                else {
                    cout << playerName << "가 " << monsterName << "을 공격합니다! " << monsterName << " 처치!" << endl;
                }
                break;
            case RecordType::playerHeal:
                cout << playerName << "가 회복 물약을 사용했습니다! 현재 체력: " << record->data << endl;
                break;
            case RecordType::playerBuff:
                cout << playerName << "가 공격력 강화 물약을 사용했습니다! 현재 공격력: " << record->data << endl;
                break;
            case RecordType::monsterAttack:
                cout << monsterName << "가 " << playerName << "을 공격합니다! " << playerName << " 체력: " << record->data << endl;
                break;
            }
        }

        if (battleResult) {
            int expReward = GameManager::Get().GetExpReward();
            int goldReward = GameManager::Get().GetGoldReward();
            int itemReward = GameManager::Get().GetItemReward();
            cout << playerName << "가 " << expReward << "EXP와 " << goldReward << " 골드를 획득했습니다." << endl;
            if (itemReward >= 0) {
                string itemName = GameManager::Get().GetPlayerItemName(itemReward);
                cout << playerName << "가 " << itemName << " 아이템을 획득했습니다!" << endl;
            }
            cout << GameManager::Get().ViewPlayerEXPAndGold() << endl << endl;
            GameManager::Get().AfterBattle();

        choiceLoop:

            cout << "1. 플레이어 상태 확인" << endl;
            cout << "2. 계속 진행" << endl;
            cout << "0. 게임 종료" << endl;
            cout << "선택: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                system("cls");
                cout << GameManager::Get().ViewPlayerStatus() << endl << endl;
                goto choiceLoop;
            }
            else if (choice == 2) {
                continue;
            }
            else if (choice == 0) {
                cout << "게임을 종료합니다." << endl;
                break;
            }
        }
        else {
            cout << playerName << "가 사망했습니다. 게임 오버!" << endl;
            break;
        }

        GetEnterInput();
    }

	return 0;
}
