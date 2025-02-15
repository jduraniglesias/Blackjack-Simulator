#pragma once
#include <string>

using namespace std;

enum class Rank {
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Jack = 11,
    Queen = 12,
    King = 13,
    Ace = 14
};
enum class Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

class Card {
private:
    Rank rank;
    Suit suit;

public:
    Card(Rank r, Suit s);
    Rank getRank() const;
    Suit getSuit() const;
    string toString() const;
};
