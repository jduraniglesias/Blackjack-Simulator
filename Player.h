#pragma once
#include <string>
#include "Deck.h"
#include "Hand.h"

using namespace std;

class Player {
private:
    string name;
    Hand playerHand;
    int balance;
    int currentBet;
    bool isStanding;

public:
    Player(const string& playerName, int startingBalance);

    void reset();
    void placeBet(int amount);
    void hit(Deck& deck);
    void stand();
    bool isBusted() const;
    bool hasBlackjack() const;
    void addWinnings(int amount);
    
    string getName() const;
    int getBalance() const;
    int getCurrentBet() const;
    string toString() const;
};
