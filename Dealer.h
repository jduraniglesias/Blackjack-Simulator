#pragma once
#include <string>
#include "Deck.h"
#include "Hand.h"

using namespace std;

class Dealer {
private:
	Hand hand;
	
public:
	int dealerTurn(Deck& deck);
	void hit(Deck& deck);
	void clear();
	bool checkBlackjack() const;
};

