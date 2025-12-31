#include <cstdlib>
#include "Database.h"
#include "Monster.h"

using namespace std;

Monster::Monster(int plLevel) {
	// - Todo : 생성자 정의 필요
	// 몬스터 스탯 설정 필요
	//  생성할 때 플레이어 레벨 기반으로 스탯 설정이 되기 때문에
	// 플레이어 레벨값을 무조건 받아서 몬스터를 생성하는 식이 필요
	// int randSize = rand() % monsterNames.size();
	// ㄴ이 위 식이 vector 랜덤 인덱스를 뽑아주니, 그걸로 사용하면 됨
}

int Monster::TakeDamage(int damage) {
	// - Todo : 기능 함수 정의 필요
	// 체력 감소를 해당 함수에서 진행
	// 그 후, 몬스터의 남은 체력을 return
	// 0 이하면 0으로 return



	// 다 만든 후에 아래 더미 return값은 지우면 됨!
	return 0;
}