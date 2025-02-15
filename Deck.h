#pragma once
#include <vector>
#include "Card.h"

class Deck {
private:
    vector<Card> cards;
    int currentIndex;

public:
    Deck();
    void reset();
    void shuffle();
    bool isEmpty() const;
    Card dealCard();
};
