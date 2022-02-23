#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

void reverse(char* start, const int len) {
	for (int i = strlen(start); i >= 0; i--)
		cout << start[i];
	cout << endl;
}


int main()
{

	ofstream file;
	ifstream iFile("input.txt");

	int fields;
	cin >> fields;

	const int size = 100 + 1;
	char line[size];

	char oLines[size];
	int len = 0;

	try
	{

		if (fields < 2 || fields > 1000)
			throw invalid_argument("Invalid argument");

		file.open("input.txt");
		for (int i = 0; i < fields; i++)
		{
			cin >> line;

			for (int k = 0; k < strlen(line); k++)
			{
				if ((line[k] < 'a' || line[k] > 'z') && (line[k] < 'A' || line[k] > 'Z'))
					throw invalid_argument("Line has others chars");
			}

			file << line << "\n";
		}
		file.close();




		for (int k = 0; k < fields; k++)
		{
			len = 0;
			iFile.getline(oLines, size);
			len = strlen(oLines);

			reverse(oLines, len);

		}


	}

	catch (const invalid_argument& ex)
	{
		cerr << ex.what() << endl;
	}

	iFile.close();

}
