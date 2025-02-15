#include "Player.h"
#include <iostream>

Player::Player(const string& playerName, int startingBalance) : name(playerName), balance(startingBalance), currentBet(0), isStanding(false) {
}

void Player::reset() {
    playerHand.clear();
    currentBet = 0;
    isStanding = false;
}

void Player::placeBet(int amount) {
    if (amount > balance) {
        cerr << "Not enough balance to place this bet\n";
        return;
    }
    currentBet = amount;
    balance -= amount;
}

void Player::hit(Deck& deck) {
    if (!isStanding) {
        playerHand.addCard(deck.dealCard());
    }
}

void Player::stand() {
    isStanding = true;
}

bool Player::isBusted() const {
    return playerHand.getTotalValue() > 21;
}

bool Player::hasBlackjack() const {
    return playerHand.getTotalValue() == 21 && playerHand.toString().find(",") == string::npos;
}

void Player::addWinnings(int amount) {
    balance += amount;
}

string Player::getName() const {
    return name;
}

int Player::getBalance() const {
    return balance;
}

int Player::getCurrentBet() const {
    return currentBet;
}

string Player::toString() const {
    return name + "'s Hand: " + playerHand.toString() + " | Balance: $" + to_string(balance);
}
