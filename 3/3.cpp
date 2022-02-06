#include <iostream>
#include <cstring>

using namespace std;

struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
};


int** CreateArray(const int rows, const int cols) {
    int** array = new int* [rows];

    for (int iRows = 0; iRows < rows; iRows++)
        array[iRows] = new int[cols];

    return array;
}

void PrintArray(int** array, const int rows, const int cols) {
    for (int iRows = 0; iRows < rows; iRows++) {
        for (int jCols = 0; jCols < cols; jCols++) {
            cout << array[iRows][jCols] << " ";
        }
        cout << endl;
    }
}

void CreateArrayStruct(const int rows, const int cols) {

    DateTime_s* ptrDTime = new DateTime_s[rows];
    DateTime_s** ptrAddresses = new DateTime_s*[rows];

    for (int i = 0; i < rows; i++)
        cin >> ptrDTime[i].year >> ptrDTime[i].month >> ptrDTime[i].day >> ptrDTime[i].hours >> ptrDTime[i].minutes >> ptrDTime[i].seconds;

    for (int j = 0; j < rows; j++)
        ptrAddresses[j] = &ptrDTime[j];
 
}

void PrintStruct(DateTime_s** ptrAddresses, const int rows) {
    for (int k = 0; k < rows; k++)
    {
        cout << ptrAddresses[k]->year << " " << ptrAddresses[k]->month << " " << ptrAddresses[k]->day << " ";
        cout << ptrAddresses[k]->hours << " " << ptrAddresses[k]->minutes << " " << ptrAddresses[k]->seconds << endl;
    }
}

void DateTimeMin(DateTime_s **ptrAddresses, const int rows, const int cols) {
    int* array = new int[cols];

    DateTime_s* minY = ptrAddresses[0];
    for (int i = 0; i < rows; i++)
    {   
    }
    PrintStruct(ptrAddresses, rows);
}

int main()
{


    int rows;
    cin >> rows;

    int cols = 6; // args in struct
    CreateArrayStruct(rows, cols);

    /*
    for (int k = 0; k < rows; k++)
    {
        cout << ptrAddreesses[k]->year << " " << ptrAddreesses[k]->month << " " << ptrAddreesses[k]->day << " ";
        cout << ptrAddreesses[k]->hours << " " << ptrAddreesses[k]->minutes << " " << ptrAddreesses[k]->seconds << endl;
    }
    */
}
