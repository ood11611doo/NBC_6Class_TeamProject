#include "BattleSystem.h"
using namespace std;

BattleSystem::BattleSystem() : monster_(nullptr) {}
BattleSystem::~BattleSystem() { DeleteMonster(); }

void BattleSystem::GenerateMonster(int plLevel) {
    DeleteMonster();
    monster_ = new Monster(plLevel); 
}

void BattleSystem::DeleteMonster() {
    if (monster_) {
        delete monster_;
        monster_ = nullptr;
    }
}
bool BattleSystem::Battle(Player* pl) { 
    if (monster_ == nullptr) {
        GenerateMonster(pl->GetLevel());
    }
    int playerHp = pl->GetHP();
    int monsterHp = monster_->GetHP();

    while (playerHp > 0 && monsterHp > 0) {
        monsterHp = monster_->TakeDamage(pl->GetAttack());

        if (monsterHp <= 0) {
            break;
        }

        playerHp = pl->TakeDamage(monster_->GetAttack());

        if (playerHp <= 0) {
            break;
        }
    }
    if (playerHp <= 0) {
        DeleteMonster(); // 외부에서 지운다면 삭제
        return false;
    }
    // 승리 보상: EXP 50, 골드 10~20, 30% 아이템 드랍
    pl->AddExp(50); // CheckLevelUp()함수 구현 보고 수정
    pl->AddGold(10 + (rand() % 11)); // 10~20 / 골드 획득 함수 연결
    // AddGold() 없으면 아래 코드로 수정
    /*int reward = 10 + (rand() % 11);
    pl->SetGold(pl->GetGold() + reward);
    */
    pl->CheckLevelUp();

    int dropRoll = (rand() % 100) + 1; // 1~100
    if (dropRoll <= 30) {
        int itemIndex = rand() % 2; // 0:포션, 1:공격부스트
        if (itemIndex == 0) pl->UseItem(0); // 아이템 획득 함수 연결 (체력)
        else pl->UseItem(1); // 아이템 획득 함수 연결 (공격)
    }
    // else (아이템 드랍 X)
    //전투 종료
   
    DeleteMonster(); // 전투가 끝나면 몬스터는 삭제 / 외부에서 삭제하면 제거
    return true; 
}