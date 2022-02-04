#include <iostream>
#include <cstring>
#include <iomanip>


using namespace std;

void printTime(const int h, const int m, const int s) {

    if (h < 0 || h > 23)
        throw "Invalid Argument";
    if (m < 0 || m > 59)
        throw "Invalid Argument";
    if (s < 0 || s > 59)
        throw "Invalid Argument";

    cout << setw(2) << setfill('0') << h << ":";
    cout << setw(2) << setfill('0') << m << ":";
    cout << setw(2) << setfill('0') << s << endl;
}

int n1()
{
    int N;
    cin >> N;

    int h, m, s;

    for (int i{ 0 }; i < N; ++i) {
        cin >> h >> m >> s;



        printTime(h, m, s);
    }
    return 0;
}

int readTime(char* iStr = '\0', int* oHours = '\0', int* oMinutes = '\0', int* oSeconds = '\0') {

    if (*oHours < 0 || *oHours > 23)
        throw "Invalid Argument";
    if (*oMinutes < 0 || *oMinutes > 59)
        throw "Invalid Argument";
    if (*oSeconds < 0 || *oSeconds > 59)
        throw "Invalid Argument";

    return 0;
}

int n2() {
    char time[255];
    char H[255];
    char M[255];
    char S[255];

    cin >> H >> M >> S;

#if 0
    for (int i = 0; i < strlen(time); i++)
    {
        cout << *(ptrTime + i);
    }
#endif


    return 0;
}

int main() {
    n2();
}