#pragma once
#include <string>
#include "Card.h"

using namespace std;

// enums for assigning cards values based
// on the card counting method being used

class Counter
{
private:
	int count;
	string strategy;
public:
	Counter();
	int getCount() const;
	int getCardValue(Card card);
	void modifyCountHiLo(Card card);
	string getStrategy();
	void setStrategy(string newStrategy);
};

