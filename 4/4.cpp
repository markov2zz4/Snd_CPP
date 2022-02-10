#include <iostream>
#include <stdexcept>

using namespace std;

struct Label_s {

	char name[16] = "";
	int age = 0;

};
struct NameStats_s {

	int cntTotal, cntLong;

};
struct AgeStats_s {

	int cntTotal, cntAdults, cntKids;

};

void CheckRight(const char* name, const int age) {

	//for (int i{ 0 }; i < strlen(name); i++)
		//if (isdigit(name[i]))
			//throw "Invalid: an argument that is not valid.";

	if (strlen(name) < 2 || strlen(name) > 15)
		throw "Invalid: an argument that is not valid.";
	if (age < 0 || age > 5000)
		throw "Invalid: an argument that is not valid.";
}

Label_s* CreateStruct(const int fields) {

	Label_s* oLabel = new Label_s[fields];

	char* waste = new char[fields * 3];

	for (int i = 0; i < fields; i++) {
		cin >> oLabel[i].name >> oLabel[i].age >> waste;
		char* pName = oLabel[i].name;
		CheckRight(pName, oLabel[i].age);
	}
	return oLabel;
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

	Label_s* oLabel{ CreateStruct(fields) };

	NameStats_s* oNameStats = new NameStats_s;
	AgeStats_s* oAgeStats = new AgeStats_s;

	calcStats(oLabel, oNameStats, oAgeStats, fields);
	PrintStruct(oNameStats, oAgeStats);
	return 0;
	}
	
	