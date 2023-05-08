#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string imeNaFile;
    string tekst;

    cout << "Vnesi ime na fajlot: ";
    cin >> imeNaFile;
    cin.ignore();
    cout << "Vnesi tekst koj ke bidi vo fajlot: ";
    getline(cin, tekst);

    ofstream file(imeNaFile.c_str(), ios::app);
    if (!file) {
        cerr << "Greska vo pronaogjanje na fajlot." << endl;
        return 1;
    }
    file<<tekst<<endl;
    file.close();

    cout<<"Tekstot e dodaen vo fajlot."<< endl;
    return 0;
}