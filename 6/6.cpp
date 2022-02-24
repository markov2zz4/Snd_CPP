#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void reverse(char* start, const int len) {

}


int main()
{

	int fields;

	const int size = 100 + 1;
	char* line = new char[size];

	int len = 0;


	try
	{
		cin >> fields;
		if (fields < 2 || fields > 1000)
			throw invalid_argument("Invalid argument");
		


		for (int i = 0; i < fields; i++)
		{
			cin >> line;

			for (int k = 0; k < strlen(line); k++)
			{
				if ((line[k] < 'a' || line[k] > 'z') && (line[k] < 'A' || line[k] > 'Z'))
					throw invalid_argument("Line has others chars");
			}
		}

	}

	catch (const invalid_argument& ex)
	{
		cerr << ex.what() << endl;
	}

}
