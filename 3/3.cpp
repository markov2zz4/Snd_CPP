#include <iostream>
#include <cstring>

using namespace std;

struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
};

unsigned long long int CountSeconds(DateTime_s* ptrAdr) {
    int DaysInMonth[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
    int DaysQuan{ 365 };
    unsigned long long Result{ 0 };
    if (ptrAdr->year % 4 == 0) {
        DaysInMonth[1]++;
        DaysQuan++;
    }
    Result = ptrAdr->year * DaysQuan;
    for (int i{ 0 }; i < ptrAdr->month - 1; i++) {
        Result += DaysInMonth[i];
    }
    Result += ptrAdr->day;
    Result = Result * 24 + ptrAdr->hours;
    Result = Result * 60 + ptrAdr->minutes;
    Result = Result * 60 + ptrAdr->seconds;
    return Result;
}

void CheckRight(const int year, const int month, const int day, const int hours, const int minutes, const int seconds) {
    if ((year < 1 || year > 5000) || (month < 1 || month > 12) || (day < 1 || day > 31))
        throw "Invalid argument";
    else if ((hours < 0 || hours > 23) || (minutes < 0 || minutes > 59) || (seconds < 0 || seconds > 59))
        throw "Invalid argument";
}

void DateTimeMin(DateTime_s** ptrAdr, const int rows) {

    int minY = 5000, minMonth = 12, minD = 31;
    int minH = 24, minMinutes = 60, minS = 60;
    //int...

    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        //DateTime_s* min = ptrAddresses[i];

        if (CountSeconds(ptrAdr[i]) <= CountSeconds(ptrAdr[index])) {
            index = i;
        }

    }

    cout << ptrAdr[index]->year << " " << ptrAdr[index]->month << " " << ptrAdr[index]->day << " ";
    cout << ptrAdr[index]->hours << " " << ptrAdr[index]->minutes << " " << ptrAdr[index]->seconds << endl;

}

DateTime_s** CreateArrayStruct(const int rows) {

    DateTime_s* ptrDTime = new DateTime_s[rows];
    DateTime_s** ptrAddresses = new DateTime_s * [rows];

    for (int i = 0; i < rows; i++) {
        cin >> ptrDTime[i].year >> ptrDTime[i].month >> ptrDTime[i].day >> ptrDTime[i].hours >> ptrDTime[i].minutes >> ptrDTime[i].seconds;
        CheckRight(ptrDTime[i].year, ptrDTime[i].month, ptrDTime[i].day, ptrDTime[i].hours, ptrDTime[i].minutes, ptrDTime[i].seconds);
    }

    for (int j = 0; j < rows; j++)
        ptrAddresses[j] = &ptrDTime[j];
    return ptrAddresses;

}

int main()
{

    int rows;
    cin >> rows;

    if (rows < 2 || rows > 50000)
        throw "Invalid argument";

    DateTime_s** ptrAddresses = CreateArrayStruct(rows);
    DateTimeMin(ptrAddresses, rows);

}