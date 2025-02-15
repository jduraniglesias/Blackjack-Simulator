#include <iostream>
#include <string>
#include "Counter.h"
using namespace std;

Counter::Counter() {
	count = 0;
	strategy = "Standard";
}

int Counter::getCount() const {
	return count;
}

int Counter::getCardValue(Card card) {
	int value = 0;
	if (strategy == "HiLo") {
		Rank rank = card.getRank();
		switch (rank) {
		case Rank::Two:
		case Rank::Three:
		case Rank::Four:
		case Rank::Five:
		case Rank::Six:
			value = 1;
			break;
		case Rank::Seven:
		case Rank::Eight:
		case Rank::Nine:
			value = 0;
			break;
		case Rank::Ten:
		case Rank::Jack:
		case Rank::Queen:
		case Rank::King:
		case Rank::Ace:
			value = 1;
			break;
		}
	}
	else if (strategy == "KO") {
		Rank rank = card.getRank();
		switch (rank) {
		case Rank::Two:
		case Rank::Three:
		case Rank::Four:
		case Rank::Five:
		case Rank::Six:
		case Rank::Seven:
			value = 1;
			break;
		case Rank::Eight:
		case Rank::Nine:
			value = 0;
			break;
		case Rank::Ten:
		case Rank::Jack:
		case Rank::Queen:
		case Rank::King:
		case Rank::Ace:
			value = 1;
			break;
		}
	}
	return value;
}

void Counter::modifyCountHiLo(Card card) {
	int value = getCardValue(card);
	count += value;
}

string Counter::getStrategy() {
	return strategy;
}

void Counter::setStrategy(string newStrategy) {
	strategy = newStrategy;
}