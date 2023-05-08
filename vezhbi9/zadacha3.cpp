#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));
    int randomBroj = rand() % 100 + 1; 
    int korisnikObid;
    int obidi = 0;

    cout<<"Generiraniot broj e pomegju 1 i 100. Obidi se da go pogodish!"<<endl;
    
    do {
        cout<<"Vnesi broj: ";
        cin>>korisnikObid;
        obidi++;

        if (korisnikObid < randomBroj) {
            cout<<"Brojot e pogolem, obidi se povtorno."<<endl;
        }
        else if (korisnikObid > randomBroj) {
            cout<<"Brojot e pomal, obidi se povtorno."<<endl;
        }
        else {
            cout<<"Chestitki! Go pogodivte brojot vo "<<obidi<<" obidi."<<endl;
        }
    } while (korisnikObid != randomBroj);

    return 0;
}