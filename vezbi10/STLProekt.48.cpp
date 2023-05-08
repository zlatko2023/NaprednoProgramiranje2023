#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {

    const string broj_indeks = "INKI937.Zlatko.Markovski";

    string email_adresa;
    cout<<"Vnesi validna email adresa na studentot: ";
    getline(cin, email_adresa);

    string celosni_info = broj_indeks + " " + email_adresa;
    cout<<celosni_info<<endl;

    vector<int> ascii_kodovi;
    for (int i = 0; i < celosni_info.length(); i++) {
        ascii_kodovi.push_back(int(celosni_info[i]));
    }

    for (size_t i = 0; i < ascii_kodovi.size(); i++) {
    	int kod = ascii_kodovi[i];
        cout<<kod<<" ";
    }
    cout<<endl;

    sort(ascii_kodovi.begin(), ascii_kodovi.end());
    for (size_t i = 0; i < ascii_kodovi.size(); i++) {
    	int kod = ascii_kodovi[i];
        cout<<kod<<" ";
    }
    cout<<endl;

	int den, mesec, godina;
	cout<<"Vnesi go datumot na ragjanje spored formatot (DD MM GG): ";
	cin>>den>>mesec>>godina;
	
	if (godina < 23) {
	    godina += 2000;
	} else {
	    godina += 1900;
	}
	
	ascii_kodovi.push_back(den / 10); 
	ascii_kodovi.push_back(den % 10); 
	ascii_kodovi.push_back(mesec / 10); 
	ascii_kodovi.push_back(mesec % 10); 
	ascii_kodovi.push_back(godina / 1000); 
	ascii_kodovi.push_back((godina / 100) % 10);
	ascii_kodovi.push_back((godina / 10) % 10); 
	ascii_kodovi.push_back(godina % 10); 

    string ime_na_file = broj_indeks + ".Proekt3";
    ofstream output_file(ime_na_file.c_str());
    for (size_t i = 0; i < ascii_kodovi.size(); i++) {
    	int kod = ascii_kodovi[i];
        output_file<<kod<<" ";
    }
    output_file.close();

    return 0;
}
