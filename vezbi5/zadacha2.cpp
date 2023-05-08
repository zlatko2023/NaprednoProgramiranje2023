#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const char* pesna = "What You Want - Evanescence";

    // Originalen string
    cout<<"Pesna: "<<pesna<<endl;
    cout<<"Prv karakter: "<<*pesna<<endl;
    cout<<"Adresa na pocetok: "<<static_cast<const void*>(pesna)<<endl;

    // Kalkulacija za zemanje na artitstot od stringot
    const char* artist = std::strchr(pesna, '-') + 2;
    ptrdiff_t offset = artist - pesna;

    // dodavanje na vrednosta od offset(artitstot) vo promenlviata pesna
    pesna += offset;

    // Modificiran string
    cout<<"\nPesna: "<<pesna<<endl;
    cout<<"Prv karakter: "<<*pesna<<endl;
    cout<<"Adresa na pocetok: "<<static_cast<const void*>(pesna)<<endl;

    return 0;
}