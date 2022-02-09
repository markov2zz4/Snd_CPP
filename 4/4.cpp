#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

struct Label_s {

	string name;
	int age = 0;

};

struct NameStats_s {

	int cntTotal, cntLong;

};

struct AgeStats_s {

	int cntTotal, cntAdults, cntKids;

};

char* slice(char* s, int from, int to)
{
	memmove(s, s + from, to - from + 1);
	s[to - from + 1] = 0;
	return s;
};

void calcStats() {

	

	//stringstream strField(str);
	//cin >> str;

	//str.erase(0, str.find(' ') + 1);

		/*for (int i = 0; i < fields; i++)
		{
			cin >> str;
			str.erase(0, str.find('let') + 1);
			stringstream(str) >> ptrLabel[i].name;
		}
		*/

}

int main() {


	int fields;
	cin >> fields;

	Label_s* oLabel = new Label_s[fields];
	//DateTime_s** ptrAddresses = new DateTime_s * [rows];

#if 0
	for (int i = 0; i < fields; i++)
	{

		cin >> name;
		name.erase(0, name.find('let')+1);
		cout << name;

		str = name;

		oLabel[i].name = name.erase(0, name.find(' ') + 1);
		

		str.erase(0, str.find('let') + 1);
		ageStream.str(str);
		ageStream >> age;
		cout << "age = " << age << endl;
		oLabel[i].age = age;
		
#endif	
		//cout << "name is " << name << endl << "age is "<< age << endl;
	}
	
	