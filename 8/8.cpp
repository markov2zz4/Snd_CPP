#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <stdexcept>

using namespace std;

const int SIZE{ 100 + 1 };

char* concat(char* pref, char* suff) {

    int len = int(strlen(pref)) + int(strlen(suff));

    char* oLine = new char[len] {};

    strcat(pref, suff);

    return pref;
}

int main()
{


    int fields{ 0 };
    char* pref{ new char[SIZE]{""} };

    try {
       cin >> fields;

        if (fields < 2 || fields > 10000)
            throw invalid_argument("Invalid Argument");


        for (int i = 0; i < fields; i++)
        {
            char* suff{ new char[100 + 1] {""}};
            cin >> suff;


            for (int k = 0; k < strlen(suff); k++)
            {
                if (((int)suff[k] < 'a' || (int)suff[k] > 'z') && ((int)suff[k] < 'A' || (int)suff[k] > 'Z')) 
                { throw invalid_argument("String contains other chars"); }

            }


            pref = concat(pref, suff);
        }

    }

    catch (const invalid_argument& value) {
        cerr << value.what() << endl;
    }

    cout << pref << endl;
}
