//Zlatko Markovski INKI937

// Overload operator - koga operatorot e preoptovaren za da izvrshi nekoja operacija, operatorot go redefinira negovoto odnesuvanje na daden tip na podatoci
//                primer ako operatorot + mozi da bidi preoptovaren za da se spojat dve nizi ama ako imame stringovi objekti, mozhime da go koristime + za da gi spoime dvata stringovi
//---------
// Friend Function - funkcija koja ima pristap do nejzinite privatni i zashtiteni clenovi iako ne e clen na klasa
//                   

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class date {
private:
    int day, month, year, hour, minute, second;

public:
    date() {}
    
    friend istream& operator >> (istream& in, date& d); //Overloading >> operator
    friend ostream& operator << (ostream& out, date& d); //Overloading << operator
    
    ~date() {}
};

istream& operator >> (istream& in, date& d)
{
    cout << "\n Enter Day : ";
    in >> d.day;
    cout << "\n Enter Month : ";
    in >> d.month;
    cout << "\n Enter Year : ";
    in >> d.year;
    cout << "\n Enter Hour : ";
    in >> d.hour;
    cout << "\n Enter Minute : ";
    in >> d.minute;
    cout << "\n Enter Second : ";
    in >> d.second;
    cout << "\n ------------------";

    if (d.month < 1 || d.month > 12) {
        cout << "\n Invalid Month";
        exit(1);
    }

    switch (d.month) {
        case 1: //January
        case 3: //March
        case 5: //May
        case 7: //July
        case 8: //August
        case 10: //October
        case 12: //December
            if (d.day < 1 || d.day > 31) {
                cout << "\n Invalid Day";
                exit(1);
            }
            break;
        case 4: //April
        case 6: //June
        case 9: //September
        case 11: //November
            if (d.day < 1 || d.day > 30) {
                cout << "\n Invalid Day";
                exit(1);
            }
            break;
        case 2:
            bool isLeap = (d.year % 100 != 0 && d.year % 4 == 0) || (d.year % 400 == 0);
            if ((isLeap && (d.day < 1 || d.day > 29)) || (!isLeap && (d.day < 1 || d.day > 28))) {
                cout << "\n Invalid Day";
                exit(1);
            }
            break;
    }
    
    if (d.hour < 0 || d.hour > 23 || d.minute < 0 || d.minute > 59 || d.second < 0 || d.second > 59) {
        cout << "\n Invalid Time";
        exit(1);
    }

    return in;
}

ostream& operator << (ostream& out, date& d)
{
    out << "\n Date : ";
    out << d.day << "-";
    out << d.month << "-";
    out << d.year << " ";
    out << d.hour << ":";
    out << d.minute << ":";
    out << d.second;
    return out;
}

int main() {
    date d;
    cout << "\n Enter Date and Time \n";
    cout << "\n ------------------";
    cin >> d;
    cout << d;
    return 0;
}