#include <iostream>
#include <string>
#include "Hand.h"

using namespace std;

Hand::Hand() {}

void Hand::clear() {
    cards.clear();
    aceCount = 0;
    totalCount = 0;
}

int Hand::getTotalValue() const {
    return totalCount;
}
//faster than adding the score everytime, just add it when drawn
void Hand::addCard(const Card& card) {
    cards.push_back(card);
    int cardValue = static_cast<int>(card.getRank());

    if (card.getRank() >= Rank::Jack && card.getRank() <= Rank::King) {
        cardValue = 10;
    }
    else if (card.getRank() == Rank::Ace) {
        aceCount++;
        cardValue = 11;
    }

    totalCount += cardValue;
    while (totalCount > 21 && aceCount > 0) {
        totalCount -= 10;
        aceCount--;
    }
}

bool Hand::isBust() const {
    return getTotalValue() > 21;
}

bool Hand::isBlackjack() const {
    return cards.size() == 2 && getTotalValue() == 21;
}

string Hand::toString() const {
    string handString;
    for (const Card& card : cards) {
        handString += card.toString() + ", ";
    }
    return handString.empty() ? "Empty Hand" : handString.substr(0, handString.size() - 2);
}

bool Hand::isSoft() const{
    return aceCount;
}

bool Hand::isPair() const{
    if (cards.size() == 2) {
        int cardOne, cardTwo;
        cardOne = static_cast<int> (cards[0].getRank());
        if (cardOne > 10 && cardOne < 14) cardOne = 10;

        cardTwo = static_cast<int> (cards[0].getRank());
        if (cardTwo > 10 && cardTwo < 14) cardTwo = 10;

        return cardOne == cardTwo;
    }
    return false;
}
