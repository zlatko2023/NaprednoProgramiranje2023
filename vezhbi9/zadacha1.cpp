#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string recenica;
    int sodrziGolemi = 0, sodrziMali = 0, sodrziBrojki = 0, sodrziSpecijalni = 0;

    cout<<"Vnesi rechenica: ";
    getline(cin, recenica);
    
    for (char c : recenica) {
        if (isupper(c))
            sodrziGolemi++;
        else if (islower(c))
            sodrziMali++;
        else if (isdigit(c))
            sodrziBrojki++;
        else if (!isspace(c))
            sodrziSpecijalni++;
    }

    cout<<"Rechenica sodrzi:\n";
    cout<<"Golemi bukvi: "<<sodrziGolemi<<endl;
    cout<<"Mali bukvi: "<<sodrziMali<<endl;
    cout<<"Broevi: "<<sodrziBrojki<<endl;
    cout<<"Specijalni karakteri: "<<sodrziSpecijalni<<endl;
    cout<<"Vkupno karakteri: "<<recenica.length()<<endl;

    return 0;
}