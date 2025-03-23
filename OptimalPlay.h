#pragma once
#include "Hand.h"
class OptimalPlay {
private:
	//H means hit, D means double down, S means stand 
	//Y means split, N means dont split (Y and N only applicable to splitpair)
	//first index is the hand total, second index is what card the dealer is showing, starts at 2 ends at Ace
	vector<vector<char>> HardTotal = {
	{'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
	{'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
	{'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
	{'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
	{'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H'},
	{'H', 'D', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'},
	{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'H', 'H'},
	{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'},
	{'H', 'H', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
	{'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
	{'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
	{'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
	{'S', 'S', 'S', 'S', 'S', 'H', 'H', 'H', 'H', 'H'},
	{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
	{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
	{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
	{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
	{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
	};
	//soft total is assuming you have an ace, therefore you can take more risk hitting and requires a diff table
	//if ace is reverted to one then its back to a hard total, can easily be checked based on the aceCount
	vector<vector<char>> SoftTotal = {
	{'H', 'H', 'H', 'D', 'D', 'H', 'H', 'H', 'H', 'H'},
	{'H', 'H', 'H', 'D', 'D', 'H', 'H', 'H', 'H', 'H'},
	{'H', 'H', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'},
	{'H', 'H', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'},
	{'H', 'D', 'D', 'D', 'D', 'H', 'H', 'H', 'H', 'H'},
	{'D', 'D', 'D', 'D', 'D', 'S', 'S', 'H', 'H', 'H'},
	{'S', 'S', 'S', 'S', 'D', 'S', 'S', 'S', 'S', 'S'},
	{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
	{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
	};
	vector<vector<char>> SplitPair = {
	{'N', 'N', 'Y', 'Y', 'Y', 'Y', 'N', 'N', 'N', 'N'},
	{'N', 'N', 'Y', 'Y', 'Y', 'Y', 'N', 'N', 'N', 'N'},
	{'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'},
	{'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'},
	{'N', 'Y', 'Y', 'Y', 'Y', 'N', 'N', 'N', 'N', 'N'},
	{'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'N', 'N', 'N', 'N'},
	{'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'},
	{'Y', 'Y', 'Y', 'Y', 'Y', 'N', 'Y', 'Y', 'N', 'N'},
	{'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'},
	{'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'},
	};

public:
	char getMove(Hand& hand, Card dealerShowing);
	int getBet(int runningCount, int decksRemaining, int bankroll, bool sleuthMode);
};
