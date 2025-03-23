#include <iostream>
#include "Dealer.h"

using namespace std;

void Dealer::clear() {
	hand.clear();
}

void Dealer::hit(Deck& deck) {
	hand.addCard(deck.dealCard());
}

int Dealer::dealerTurn(Deck& deck) {
	while (hand.getTotalValue() < 17) {
		hit(deck);
	}
	return hand.getTotalValue();
}

bool Dealer::checkBlackjack() const {
	return hand.isBlackjack();
}
