#include <iostream>
#include "Card.h"

using namespace std;

Card::Card(Rank r, Suit s) : rank(r), suit(s) {}

Rank Card::getRank() const {
    return rank;
}

Suit Card::getSuit() const {
    return suit;
}

string Card::toString() const {
    static const string rankStrings[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    static const string suitStrings[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    return rankStrings[static_cast<int>(rank) - 2] + " of " + suitStrings[static_cast<int>(suit)];
}
