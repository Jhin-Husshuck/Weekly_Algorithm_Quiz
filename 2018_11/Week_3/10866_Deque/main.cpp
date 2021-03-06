#include "Deque.h"
#include <iostream>

int main() {
	Deque* deque = new Deque();	//Custom Deque

	int orderCnt;

	std::cin >> orderCnt;

	for (int i = 0; i < orderCnt; i++) {
		char orderName[20];
		scanf("%s", orderName);	//Get the name of order from console

		Deque::OrderType orderType = Deque::ConvertToOrder(orderName); //Convert string to enum type

		switch (orderType) {	//Uses enum type to use Switch statement
		case Deque::Push_Back: {
			int data;
			scanf("%d", &data);
			deque->PushBack(data);
			break;
		}
		case Deque::Push_Front: {
			int data;
			scanf("%d", &data);
			deque->PushFront(data);
			break;
		}
		case Deque::Pop_Front: {
			deque->PopFront();
			break;
		}
		case Deque::Pop_Back: {
			deque->PopBack();
			break;
		}
		case Deque::Front: {
			deque->PrintFront();
			break;
		}
		case Deque::Back: {
			deque->PrintBack();
			break;
		}
		case Deque::Size: {
			deque->PrintSize();
			break;
		}
		case Deque::Empty: {
			deque->PrintIsEmpty();
			break;
		}
		}
	}
}
