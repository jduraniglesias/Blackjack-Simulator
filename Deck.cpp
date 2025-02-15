#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include "Deck.h"

using namespace std;

Deck::Deck() {
    reset();
}

void Deck::reset() {
    cards.clear();
    currentIndex = 0;

    for (int suit = 0; suit <= 3; suit++) {
        for (int rank = 2; rank <= 14; rank++) {
            Rank cardRank = static_cast<Rank>(rank);
            Suit cardSuit = static_cast<Suit>(suit);
            cards.emplace_back(cardRank, cardSuit);
        }
    }

    shuffle();
}

void Deck::shuffle() {
    random_device rd;
    mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
    currentIndex = 0;
}

bool Deck::isEmpty() const {
    return currentIndex >= static_cast<int>(cards.size());
}

Card Deck::dealCard() {
    if (isEmpty()) {
        throw runtime_error("No more cards in the deck");
    }
    return cards[currentIndex++];
}
