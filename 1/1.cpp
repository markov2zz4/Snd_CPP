#include <iostream>
#include <stdio.h>

using namespace std;

void printTime(const int h, const int m, const int s) {
    printf("%02d:%02d:%02d\n", h, m, s);

}

int main()
{
    int N;
    cin >> N;

    int h, m, s;

    for (int i{ 0 }; i < N; ++i) {
        cin >> h >> m >> s;

        if (h < 0 || h > 23)
            throw "Invalid Argument";
        if (m < 0 || m > 59)
            throw "Invalid Argument";
        if (s < 0 || s > 59)
            throw "Invalid Argument";

        printTime(h, m, s);
    }
    return 0;
}


