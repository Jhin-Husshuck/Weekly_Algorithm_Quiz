#include <iostream>
#include <queue>
#include <string>

#define MAX_SIZE 10000

struct Vector2 {
	int depth=0;//used for check whether this Vector2 object is visited
	int letter=0;//integer code to print the 'D, S, L, R' letter at the end, using tetramal
	int lastLetter = 0;//saves the letter until the next depth check
};

class ArrayList {
	Vector2 data[MAX_SIZE];

public:

	bool Push(int _newData, int _newLetter, int _depth) {
		if (data[_newData].depth != _depth) {//depth check to prevent multiple queue push
			data[_newData].depth = _depth;
			data[_newData].lastLetter = data[_newData].letter;
			data[_newData].letter = _newLetter;

			return true;
		}
		else {
			data[_newData].letter = _newLetter;
			return false;
		}
	}

	Vector2 GetData(int index) {
		return data[index];
	}

	void Refresh() {
		data[0].depth = 0;
		data[0].letter = 0;
	}
};

bool Double(int value, int letter, int depth, ArrayList& list);
bool Sub(int value, int letter, int depth, ArrayList& list);
bool LeftShift(int value, int letter, int depth, ArrayList& list);
bool RightShift(int value, int letter, int depth, ArrayList& list);
char PrintLetter(int index);

int start, target;
std::queue<int> queue;
int main() {
	int time;
	scanf("%d",&time);

	for (int i = 0; i < time; i++) {
		ArrayList list;
		scanf("%d %d",&start,&target);

		queue.push(start);	//Push the initial data

		bool flag = false;	//has found answer

  	int value = 0;
		int depth=0;

		while (!flag) {
			depth++;
			int length = queue.size();
			for (int i = 0; i < length; i++) {
				value = queue.front();
				Vector2 temp = list.GetData(value);
				int letter = temp.letter;

				if (temp.depth == depth) {	//if current Vector2 is already visited in same depth, use lastLetter as letter value instead
					letter = temp.lastLetter;
				}
				if (value != 0) {
					if (Double(value, letter, depth, list)) {
						flag = true;
						break;
					}
				}
				if (Sub(value, letter, depth, list)) {
					flag = true;
					break;
				}
				if (letter % 4 != 3) {
					if (LeftShift(value, letter, depth, list)) {
						flag = true;
						break;
					}
				}
				if (letter % 4 != 2) {
					if (RightShift(value, letter, depth, list)) {
						flag = true;
						break;
					}
				}
				queue.pop();

			}
		}

		//parse the letter integer to tetramal to print the result message
		int message [30];
		int temp = list.GetData(target).letter;
		//std::cout << depth << " " <<temp<< " ";
		for (int i = 0; i < depth; i++) {
			message[depth - i - 1] = temp % 4;
			temp /= 4;
		}
		std::string str("");
		for (int i = 0; i < depth; i++) {
		str+= PrintLetter(message[i]);
		}
		std::cout <<str <<"\n";
		while (!queue.empty()) {
			queue.pop();
		}
	}

}

char PrintLetter(int index) {
	switch (index) {
	case 0: {
		return 'D';
		break;
	}
	case 1: {
		return 'S';
	}
	case 2: {
		return 'L';
	}
	case 3: {
		return 'R';
	}
	}
}
//doubles the
bool Double(int _value, int letter, int depth,ArrayList& list) {
	int value = 2*_value;
	if (value >= 10000) value -= 10000;
	if(list.Push(value, letter*4+0, depth)) queue.push(value);
	return (value == target);
}

bool Sub(int _value, int letter, int depth,ArrayList& list) {
	int value = _value-1;
	if (value < 0) value = 9999;
	if (list.Push(value, letter * 4 + 1, depth)) queue.push(value);
	return (value == target);
}

bool LeftShift(int _value, int letter, int depth, ArrayList& list) {
	int value = (_value * 10) % 10000 + _value / 1000;
	if (list.Push(value, letter * 4 + 2, depth)) queue.push(value);
	return (value == target);
}

bool RightShift(int _value, int letter, int depth, ArrayList& list) {
	int value = (_value % 10) * 1000 + _value / 10;
	if (list.Push(value, letter * 4 + 3, depth)) queue.push(value);
	return (value == target);
}
