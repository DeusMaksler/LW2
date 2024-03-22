#include <iostream>
#include <queue>
using namespace std;

void createDeck(queue<int>& deck) {
	for (int i = 0; i < 5; i++) {
		int card;
		cin >> card;
		deck.push(card);
	}
}

int main()
{
	queue<int> firstDeck;
	queue<int> secondDeck;

	createDeck(firstDeck);
	createDeck(secondDeck);

	int moves = 0;

	while (moves < 1000000 && !firstDeck.empty() && !secondDeck.empty()) {
		int firstCard = firstDeck.front();
		firstDeck.pop();

		int secondCard = secondDeck.front();
		secondDeck.pop();

		if (firstCard > secondCard) {
			if (secondCard == 0 && firstCard == 9) {
				secondDeck.push(firstCard);
				secondDeck.push(secondCard);
			} else {
				firstDeck.push(firstCard);
				firstDeck.push(secondCard);
			}
		}
		else {
			if (firstCard == 0 && secondCard == 9) {
				firstDeck.push(firstCard);
				firstDeck.push(secondCard);
			} else {
				secondDeck.push(firstCard);
				secondDeck.push(secondCard);
			}
		}

		//if ((firstCard > secondCard && (secondCard != 0 && firstCard != 9)) || (firstCard == 0 && secondCard == 9)) {
		//	firstDeck.push(firstCard);
		//	firstDeck.push(secondCard);
		//}
		//else {
		//	secondDeck.push(firstCard);
		//	secondDeck.push(secondCard);
		//}
		moves++;
	}

	if (firstDeck.empty()) cout << "second " << moves;
	else if (secondDeck.empty()) cout << "first " << moves;
	else cout << "botva ";
}