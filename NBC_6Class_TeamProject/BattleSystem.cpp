#include "BattleSystem.h"
using namespace std;

BattleSystem::BattleSystem() : monster_(nullptr), recentMonsterName(""), battleReward(nullptr) {}
BattleSystem::~BattleSystem() { DeleteMonster(); }

void BattleSystem::GenerateMonster(int plLevel) {
    DeleteMonster();
    monster_ = new Monster(plLevel, recentMonsterName); 
}

void BattleSystem::DeleteMonster() {
    if (monster_) {
        delete monster_;
        monster_ = nullptr;
    }
}
bool BattleSystem::Battle(Player* pl) {
    ClearLog();
    if (monster_ == nullptr) {
        GenerateMonster(pl->getLevel());
    }
    recentMonsterName = monster_->GetMonsterName();

    int playerHp = pl->getHp();
    int monsterHp = monster_->GetMonsterHp();

    while (playerHp > 0 && monsterHp > 0) {
        bool attackSkip = false;

        int attackItemChance = rand() % 100;
        if (attackItemChance < PLAYER_POTION_ATTACK_CHANCE) {
            int attackItemIndex = pl->ReturnItemCount(1);
            if (attackItemIndex > 0) {
                pl->UseItem(attackItemIndex);
                battleRecords.push_back(new BattleRecord{ RecordType::playerBuff, pl->getTotalAtk() });
                attackSkip = true;
            }
        }

        if (!attackSkip && pl->getHp() <= (pl->getMaxHp() * PLAYER_POTION_HEALTH_PERCENT) / 100) {
            int healthItemChance = rand() % 100;
            if (healthItemChance < PLAYER_POTION_HEALTH_CHANCE) {
                int healthItemIndex = pl->ReturnItemCount(0);
                if (healthItemIndex != -1) {
                    pl->UseItem(healthItemIndex);
                    battleRecords.push_back(new BattleRecord{ RecordType::playerHeal, pl->getHp() });
                    attackSkip = true;
                }
            }
        }

        if (!attackSkip) {
            monsterHp = monster_->TakeDamage(pl->getTotalAtk());
            battleRecords.push_back(new BattleRecord{ RecordType::playerAttack, monsterHp });
            if (monsterHp <= 0) {
                break;
            }
        }

        playerHp = pl->TakeDamage(monster_->GetMonsterAttack());
        battleRecords.push_back(new BattleRecord{ RecordType::monsterAttack, playerHp });
        if (playerHp <= 0) {
            break;
        }
    }

    if (playerHp <= 0) {
        return false;
    }

    int expAdded = 50;
    int goldAdded = 10 + (rand() % 11);
    int itemGetIndex = -1;

    int dropRoll = (rand() % 100) + 1;
    if (dropRoll <= 30) {
        int itemIndex = rand() % 2;
        if (itemIndex == 0) {
            pl->AddItemByIndex(0);
            itemGetIndex = 0;
        } else {
            pl->AddItemByIndex(1);
            itemGetIndex = 1;
        }
    }

    battleReward = new BattleReward();
    battleReward->exp = expAdded;
    battleReward->gold = goldAdded;
    battleReward->itemIndex = itemGetIndex;

    pl->addExp(expAdded);
    pl->addGold(goldAdded);
    pl->CheckLevelUp();

    return true; 
}
void BattleSystem::ClearLog() {
    for (const auto& inners : battleRecords) {
        if (inners != nullptr) {
            delete inners;
        }
    }
    battleRecords.clear();

    delete battleReward;
    battleReward = nullptr;
}
