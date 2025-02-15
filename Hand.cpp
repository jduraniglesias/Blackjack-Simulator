#include <iostream>
#include <string>
#include "Hand.h"

using namespace std;

Hand::Hand() {}

void Hand::clear() {
    cards.clear();
}

int Hand::getTotalValue() const {
    int total = 0;
    int aceCount = 0;

    for (const Card& card : cards) {
        int cardValue = static_cast<int>(card.getRank());

        if (card.getRank() >= Rank::Jack && card.getRank() <= Rank::King) {
            cardValue = 10;
        }
        else if (card.getRank() == Rank::Ace) {
            aceCount++;
            cardValue = 11;
        }

        total += cardValue;
    }

    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }

    return total;
}

void Hand::addCard(const Card& card) {
    cards.push_back(card);
}

bool Hand::isBust() const {
    return getTotalValue() > 21;
}

string Hand::toString() const {
    string handString;
    for (const Card& card : cards) {
        handString += card.toString() + ", ";
    }
    return handString.empty() ? "Empty Hand" : handString.substr(0, handString.size() - 2);
}
