#include <iostream>
#include <string>

using namespace std;

const int SIZE = 255;

typedef struct Tokens_s {

	int num;
	char** str;

} Tokens;

void printStr(char* ptrStr, const int size) {
	for (int i{ 0 }; i < size; ++i)
		cout << ptrStr[i];
	cout << endl;
}

int main() {

	char* str = new char[SIZE] {""};

	printStr(str, SIZE);

}