#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Hand {
private:
    vector<Card> cards;

public:
    Hand();
    void clear();
    int getTotalValue() const;
    void addCard(const Card& card);
    bool isBust() const;
    string toString() const;
};
