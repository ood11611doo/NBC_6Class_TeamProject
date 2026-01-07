#pragma once
#include <string>
#include "Database.h"

class Player;

class Item {
public:
	virtual ~Item() = default;

	virtual std::string GetName() const = 0;
	virtual int GetPrice() const = 0;
	virtual int GetCount() const = 0;
	virtual int SetCount(int InCount) = 0;
	virtual int AddCount(int InCount) = 0;
	virtual void Use(Player* InPlayer) = 0;
};
