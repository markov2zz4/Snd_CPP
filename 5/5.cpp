#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void calcLetters(char* iStr, int* oLowerCnt, int* oUpperCnt, int* oDigitsCnt) {

	for (int i = 0; i < (int)strlen(iStr); i++)
	{
		if (iStr[i] >= 'a' && iStr[i] <= 'z') *oLowerCnt += 1;
		if (iStr[i] >= 'A' && iStr[i] <= 'Z') *oUpperCnt += 1;
		if (iStr[i] >= '0' && iStr[i] <= '9') *oDigitsCnt += 1;
	}
}

int main() {
	const int size = 100 + 1;
	char lines[size];

	ifstream file("input.txt");
	int i{ 0 };

	int Lower{ 0 };
	int Upper{ 0 };
	int Digits{ 0 };
	int len{ 0 };

	while (true)
	{
		

		i++;
		file.getline(lines, size);

		if (file.eof())
			break;

		len = 0;
		Lower = 0; Upper = 0; Digits = 0;

		len = strlen(lines);
		calcLetters(lines, &Lower, &Upper, &Digits);

		cout << "Line " << i << " has " << len << " chars: " << Lower + Upper << 
		" are letters (" << Lower << " lower, " << Upper << " upper), " << Digits << " are digits." << endl;
		
		

	}
	file.close();
	return 0;
}