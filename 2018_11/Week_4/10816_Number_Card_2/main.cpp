#include <iostream>
#include <algorithm>

#include "BinarySearch.h"

#define _MAX_SIZE 500050

int cardData[_MAX_SIZE];
int testData[_MAX_SIZE];

int main() {
	int cardNum;
	scanf("%d", &cardNum);

	for (int i = 0; i < cardNum; i++) {
		scanf("%d", &cardData[i]);
	}

	std::sort(cardData, cardData + cardNum);

	int testNum;
	scanf("%d", &testNum);

	for (int i = 0; i < testNum; i++) {
		scanf("%d", &testData[i]);
	}

	for (int i = 0; i < testNum; i++) {
		printf("%d ", BinarySearch::ContainsAll(testData[i], cardData, cardNum));
	}
}
