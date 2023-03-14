#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    // Koristenje na 3 nizi za znacite, brojkata i dzokerite
    string znaci[] = {"Srce", "Baklava", "Detelina", "List"};
    string brojka[] = {"Kec", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Dzandar", "Chupa", "Pop"};
    string dzokeri[] = {"Crven Joker", "Crn Joker"};

    string shpil[54]; // shpil niza kade gi sobiram site 52 karti + 2 dzokeri

    int i = 0;
    // kreiranje na niza od stringovi za sekoja karta so negovata brojka i simbol
    for (string znak : znaci) {
        for (string broj : brojka) {
            shpil[i++] = broj + " " + znak;
        }
    }
    // dodavanje na dzokerite vo shpilot
    for (string dzoker : dzokeri) {
        shpil[i++] = dzoker;
    }
    
    // pechatenje na elementite od nizata shpil neizmeshani
    cout<<"NEIZMESHANI:"<<endl;
    for (int i = 0; i < 54; i++) {
        cout<<shpil[i]<<endl;
    }

    // meshanje na kartite so pomosh na funkcijata swap, odnosno kreiranje na random broj vo promenliva i zamenuvanje na momentalniot indeks na elementot so random brojot kako indeks
    srand(time(nullptr));
    for (int i = 53; i >= 1; i--) {
        int j = rand() % i;
        swap(shpil[i], shpil[j]);
    }

    // pechatenje na elementite od nizata shpil izmeshani
    cout<<"\n\nIZMESHANI:"<<endl;
    for (int i = 0; i < 54; i++) {
        cout<<shpil[i]<<endl;
    }

    return 0;
}

