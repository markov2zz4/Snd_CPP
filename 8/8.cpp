#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

char* concat(char* pref, char* suff) {
    strcat(pref, suff);
    return pref;
}

int main()
{
    int fields{ 0 };
    std::cin >> fields;

    if (fields < 2 || fields > 10000)
        return -1;

    char* pref{ new char[100 + 1]{""}};
    

    for (int i = 0; i < fields; i++)
    {
        char* suff{ new char[100 + 1] };
        std::cin >> suff;
        

        for (int k = 0; k < strlen(suff); k++)
        {
            if (((int)suff[k] < 'a' || (int)suff[k] > 'z') && ((int)suff[k] < 'A' || (int)suff[k] > 'Z'))
                return -1;

        }
        pref = concat(pref, suff);
    }

    
    cout << pref << endl;
}
