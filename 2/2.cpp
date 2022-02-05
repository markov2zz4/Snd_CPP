#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <stddef.h>

using namespace std;


int readTime(const char* iStr, int* ptrH, int* ptrM, int* ptrS) {

    short int result = 1;

    for (int i = 0; i < strlen(iStr); i++)
    {
        if (iStr[i] == unsigned char(124) || iStr[i+1] == unsigned char(124))
            result = -1;
        break;
    }

    //Invalid Arguments
    if ((*ptrH < 0 || *ptrH > 23) || (*ptrM < 0 || *ptrM > 59) || (*ptrS < 0 || *ptrS > 59) || result == -1) {
        
        result = 0;
        *ptrH = -1, *ptrM = -1, *ptrS = -1;

        cout << result << " " << *ptrH << " " << *ptrM << " " << *ptrS << endl;
        ptrS = NULL;

        cout << result << " " << *ptrH << " " << *ptrM << endl;
        ptrM = NULL;

        cout << result << " " << *ptrH << endl;
        return 0;
    }

    else if (ptrS == NULL) {
        cout << result << " " << *ptrH << " " << *ptrM << endl;
    }
        
    else if (ptrM == NULL) {
        ptrS = NULL;
        cout << result << " " << *ptrH << endl;

    }

    else {
        cout << result << " " << *ptrH << " " << *ptrM << " " << *ptrS << endl;
        ptrS = NULL;

        cout << result << " " << *ptrH << " " << *ptrM << endl;
        ptrM = NULL;

        cout << result << " " << *ptrH << endl;
    }


}

int main() {


    char time[255];
    cin >> time;

    const char* ptrTime = time;

    int* ptrHours = NULL;
    int* ptrMinutes = NULL;
    int* ptrSeconds = NULL;

    int H = 0, M = 0, S = 0;
    sscanf(time, "%d:%d:%d", &H, &M, &S);

    ptrHours = &H;
    ptrMinutes = &M;
    ptrSeconds = &S;

    readTime(time, ptrHours, ptrMinutes, ptrSeconds);

    return 0;
}