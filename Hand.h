#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Hand {
private:
    vector<Card> cards;
    char totalCount = 0;
    char aceCount = 0;
public:
    Hand();
    void clear();
    int getTotalValue() const;
    void addCard(const Card& card);
    bool isBust() const;
    bool isBlackjack() const;
    string toString() const;
    bool isSoft() const;
    bool isPair() const;
};
