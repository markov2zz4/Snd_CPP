#include <iostream>
#include <stdexcept>
#include <cstring>

using namespace std;

typedef struct Label_s {

	char name[16] = "";
	int age = 0;

}Label;

typedef struct NameStats_s {

	int cntTotal, cntLong;

}NameStats;

typedef struct AgeStats_s {

	int cntTotal, cntAdults, cntKids;

}AgeStats;

void CheckRight(const int fields ,const char* name, const int age) {
	auto i = 0;

	while (name[i])
	{
		if (name[i] >= '0' && name[i] <= '9') { throw invalid_argument("Invalid: an argument that is not valid."); }
		i++;
	}

	if (strlen(name) < 1 || strlen(name) > 15)
		throw invalid_argument("Invalid: an argument that is not valid.");

	if (age < 0 || age > 5000)
		throw invalid_argument("Invalid: an argument that is not valid.");
}


void calcStats(Label_s* oLabel, NameStats_s* oNameStats, AgeStats_s* oAgeStats, const int fields) {

	int cntTotalAge{0}, cntAdults{ 0 }, cntKids{ 0 };
	int cntTotalName{0}, cntLong{ 0 };

	for (int i{ 0 }; i < fields; i++) {

		if (strlen(oLabel[i].name) > 10) cntLong++;

		if (oLabel[i].age >= 18) cntAdults++;
		else if (oLabel[i].age < 14) cntKids++;

		cntTotalAge++; cntTotalName++;
	}

	oNameStats->cntLong = cntLong;
	oNameStats->cntTotal = cntTotalName;

	oAgeStats->cntAdults = cntAdults;
	oAgeStats->cntKids = cntKids;
	oAgeStats->cntTotal = cntTotalAge;
}

void PrintStruct(NameStats_s* oNameStats, AgeStats_s* oAgeStats) {
	cout << "names: total = " << oNameStats->cntTotal << endl;
	cout << "names: long = " << oNameStats->cntLong << endl;

	cout << "ages: total = " << oAgeStats->cntTotal << endl;
	cout << "ages: adult = " << oAgeStats->cntAdults << endl;
	cout << "ages: kid = " << oAgeStats->cntKids << endl;

}

int main() {


	int fields;
	cin >> fields;
	
	const char* test = "Zoya";
	cout << strlen(test);

	char* waste = new char[fields];
	Label_s* oLabel = new Label_s[fields];

	for (int i = 0; i < fields; i++) {
		cin >> oLabel[i].name >> oLabel[i].age >> waste;
		CheckRight(fields, oLabel[i].name, oLabel[i].age);
	}

	try {
		if (fields < 1 || fields > 1000)
			throw invalid_argument("Invalid: an argument that is not valid.");

	}
	catch (const invalid_argument &ex) // обработчик исключений типа const char*
	{
		std::cerr << ex.what() << endl;
	}


	NameStats_s* oNameStats = new NameStats_s;
	AgeStats_s* oAgeStats = new AgeStats_s;

	calcStats(oLabel, oNameStats, oAgeStats, fields);
	PrintStruct(oNameStats, oAgeStats);
	return 0;
	}
	
	