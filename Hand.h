#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Hand {
private:
    vector<Card> cards;

public:
    Hand();
    void addCard(const Card& card);
    int getTotalValue() const;
    bool isBust() const;
    void clear();
    string toString() const;
};
