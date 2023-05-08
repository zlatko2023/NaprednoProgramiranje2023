#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funkcija koja generira simboli
char znakSimbol() {
    const string simboli = "!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`";
    return simboli[rand() % simboli.length()];
}

// Funkcija koja gi promenuva prvite simboli od imeto i prezimeto
void promeniString(string& ime) {
    int n = ime.length();
    if (n < 2) return;
    int brojSimboli = (n == 3) ? 2 : 4;
    for (int i = 0; i < brojSimboli; i++) {
        ime[i] = znakSimbol();
    }
}

int main() {
    string Ime = "Zlatko";
    string Prezime = "Markovski";
    
    // Original
    cout<<"Ime: "<<Ime<<endl;
    cout<<"Prezime: "<<Prezime;
    
    // Povikanje na funkcijata za promena na imeto
    promeniString(Ime);
    promeniString(Prezime);
    
    // Promenite
    cout<<"\n\nIme: "<<Ime<<endl;
    cout<<"Prezime: "<<Prezime;
    
    return 0;
}
