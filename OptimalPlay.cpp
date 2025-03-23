#include "OptimalPlay.h"
using namespace std;
char OptimalPlay::getMove(Hand& hand, Card dealerShowing) {
	int totalHand = hand.getTotalValue();
	bool isSoft = hand.isSoft();
	int dealerCard = static_cast<int> (dealerShowing.getRank());
	if (dealerCard > 10 && dealerCard < 14) dealerCard = 10;
	if (dealerCard == 14) dealerCard = 11;

	if (hand.isPair()) {
		return SplitPair[(totalHand / 2) - 2][dealerCard - 2];
	}
	if (hand.isSoft()) {
		return SoftTotal[totalHand - 13][dealerCard - 2];
	}
	return HardTotal[totalHand - 4][dealerCard - 2];
}
//sleuthMode means if you are trying to avoid casino detection, making higher and higher bets is good
//but if you bet too high when your at an advantage then the casino gets suspicious
//sleuth mode true means capped bets, false means uncapped bet
int OptimalPlay::getBet(int runningCount, int decksRemaining, int bankroll, bool sleuthMode){
	int trueCount = runningCount / decksRemaining;
	int bettingUnit = bankroll / 1000;
	int totalBetSize = bettingUnit * (trueCount - 1);
	if (totalBetSize < 5) totalBetSize = 5;
	if (totalBetSize > bankroll / 4 && sleuthMode) totalBetSize = bankroll / 4;
	return totalBetSize;
}
