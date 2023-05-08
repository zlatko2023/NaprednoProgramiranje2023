// Zlatko Markovski INKI937
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <sys/stat.h>

using namespace std;

struct student{
    string ime;
    string prezime;
    string indeks;
};

char tocniPrvi[4]={'a', 'a', 'c', 'a'};
char tocniVtori[4]={'a', 'a', 'a', 'a'};
char tocniTreti[4][2]={{'b', 'd'}, {'c', 'd'}, {'a', 'd'}, {'c', 'e'}};


// funkcija za proveruvanje dali fajlot postoi
bool fileExists(const string &filename) {
    struct stat buf;
    return (stat(filename.c_str(), &buf) == 0);
}

// funckijata za dobivanje na datumot i vremeto
string getTimestamp() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", timeinfo);
    return string(buffer);
}

// Funkcija koja se koristi za primanje na vlez

void studentInput(student &lice){
    cout<<"Vnesete go imeto na studentot: ";
        cin>>lice.ime;
    cout<<"Vnesete go prezimeto na studentot: ";
        cin>>lice.prezime;

    do{
        cout<<"Vnesete go indeksot na studentot: ";
        cin>>lice.indeks;
    } while(lice.indeks.size()!=3 && lice.indeks.size()!=4);
}

// Funkcija koja se koristi za zapishuvanje na odgovorot vo datoteka

void writeOdgovor(fstream &file, char odg, char odg2, int br) {
    file << br << ". " << odg << " " << odg2 << endl;
}

// Funkcija koja se koristi za proverka na odgovorot i boduvanje
float checkOdgovor(int brojnaprasanje, char answer, char answer2){

    if (brojnaprasanje <= 4){
      if ( answer == tocniPrvi[brojnaprasanje-1] )
        return 1.5;
    }
    else if (brojnaprasanje > 4 && brojnaprasanje <= 8 ){
      if ( answer == tocniVtori[brojnaprasanje-5] )
        return 3;
    }
    else if (brojnaprasanje > 8 && brojnaprasanje <= 12 ){
      if ((( answer == tocniTreti[brojnaprasanje-9][0] ) && ( answer2 == tocniTreti[brojnaprasanje-9][1] )) || (( answer == tocniTreti[brojnaprasanje-9][1] ) && ( answer2 == tocniTreti[brojnaprasanje-9][0] )))
        return 8;
    }
}

// Funkcija koja ovozmozuva proverka na vnes kaj odgovorot i ispishuvanje na odgovorot vo datoteka

float handleInput(int brojprasanje, fstream &file){

    char odgovor,odgovor2;
    if (brojprasanje <= 4){
      do{
        cout<<"Vashiot odgovor: ";
        cin>>odgovor;
      } while( odgovor != 'a' && odgovor != 'b' && odgovor != 'c' );
      writeOdgovor(file, odgovor, ' ', brojprasanje);
    }
    else if (brojprasanje > 4 && brojprasanje <= 8 ){
        do{
          cout<<"Vashiot odgovor: ";
          cin>>odgovor;
        } while( odgovor != 'a' && odgovor != 'b' && odgovor != 'c' && odgovor != 'd' );
        writeOdgovor(file, odgovor, ' ', brojprasanje);
      }
    else if (brojprasanje > 8 && brojprasanje <= 12 ){
        do{
          cout<<"Vashiot odgovor: ";
          cin>>odgovor;
        } while( odgovor != 'a' && odgovor != 'b' && odgovor != 'c' && odgovor != 'd' && odgovor != 'e' );
        do{
          cout<<"Vashiot odgovor: ";
          cin>>odgovor2;
        } while(( odgovor2 == odgovor )  || ( odgovor2 != 'a' && odgovor2 != 'b' && odgovor2 != 'c' && odgovor2 != 'd' && odgovor2 != 'e' ));
         writeOdgovor(file, odgovor, odgovor2, brojprasanje);
      }

      return checkOdgovor(brojprasanje, odgovor, odgovor2);
    }

// Funkcija koja se koristi za proverka na poeni i vrakanje na vrednosta na ocenkata
int score(float poeni){
    if ( poeni >= 0 && poeni <= 24 )
      return 5;
    else if ( poeni >= 25 && poeni <= 32 )
      return 6;
    else if ( poeni >= 32.5 && poeni <= 37 )
      return 7;
    else if ( poeni >= 37.5 && poeni <= 40.5 )
      return 8;
    else if ( poeni >= 41 && poeni <= 45 )
      return 9;
    else if ( poeni >= 45.5 && poeni <= 50 )
      return 10;
}

// Funkcija za pechatenje na tabela so tochnite odgovori

void answersTable(){
    cout<<"Tocni odgovori na prasanjata se:"<<endl;
    for(int i=1;i<=12;i++){
      if (i <= 4)
        cout<<i<<". "<<tocniPrvi[i-1]<<endl;
        else if (i > 4 && i <= 8 )
          cout<<i<<". "<<tocniVtori[i-5]<<endl;
            else if (i > 8 && i <= 12 )
              cout<<i<<". "<<tocniTreti[i-9][0] << " " <<tocniTreti[i-9][1]<<endl;
    }
}


// dodavanje na pocetnite informaciite vo fajlot od korisnikot
void writeAnswerFileHeader(fstream &file, const student &lice, const string &startTime) {
    file << "Ime: " << lice.ime << endl;
    file << "Prezime: " << lice.prezime << endl;
    file << "Indeks: INKI" << lice.indeks << endl;
    file << "Vreme na start: " << startTime << endl;
}

// dodavanje na krajnite informaciite vo fajlot od korisnikot
void writeAnswerFileFooter(fstream &file, float poeni, int ocenka, const string &endTime, const string &odgovori_filename) {
    file << "Vreme na kraj: " << endTime << endl << endl;
    file << "-----------------------------" << endl;
    file << "Poeni: " << poeni << endl;
    file << "Ocenka: " << ocenka << endl;
    file << "-----------------------------" << endl;
    file << "Pishani odgovori:" << endl;

    // Pecatenje na odgovorite od fajlot odgovori_imeiprezime
    ifstream odgovori_file;
    odgovori_file.open(odgovori_filename.c_str(), ios::in);
    string line;
    while (getline(odgovori_file, line)) {
        file << line << endl;
    }
    odgovori_file.close();
    remove(odgovori_filename.c_str());
}

// ispushuvanje na zaglavieto no. time-stamp ime, prezime i indeks vo fajlot Students.log
void writeStudentsLogHeader() {
    fstream studentsLog;
    if (!fileExists("Students.log")) {
        studentsLog.open("Students.log", ios::out);
        studentsLog << "no.; (time-stamp); Ime; Prezime; Indeks." << endl;
        studentsLog.close();
    }
}


// proverka kolku redovi ima fajlot
int countLinesInFile(const string &filename) {
    ifstream file(filename.c_str());
    int count = 0;
    string line;
    while (getline(file, line)) {
        count++;
    }
    return count;
}

int main(){

    fstream file, odgovori_file, test, studentsLog;
    student lice;
    string prasanje;
    int brojnaprasanje = 1;
    float poeni = 0;
    studentInput(lice);

	// Kreiranje na datotekata so ime i prezime, i proverka dali postoi so toa ime

    const string filename = lice.ime + lice.prezime + "INKI" + lice.indeks;
    const string odgovori_filename = "odgovori_" + lice.ime + lice.prezime + "INKI" + lice.indeks;
    if (fileExists(filename)) {
        cout << "Fajlot so toa ime vekje postoi i korisnikot nema pravo na povtorno odgovaranje" << endl;
        return 1;
    }

    file.open(filename.c_str(), ios::out);
    file.close();

	// Funkcija za ispishuvanje na headerot vo Students.log
	writeStudentsLogHeader();

	// promenliva so vrednost od feedback-ot na funckiajta countLinesInFile
    int entryNumber = countLinesInFile("Students.log");

	// otvoranje na Students.log file i kreiranje nov red vo istiot fajl so podatoci od studentot
    studentsLog.open("Students.log", ios::app);
    studentsLog << entryNumber << ". " << getTimestamp() << "; " << lice.ime << "; " << lice.prezime << "; " << lice.indeks << endl;
    studentsLog.close();

    string startTime = getTimestamp();

    file.open(filename.c_str(), ios::out);
    writeAnswerFileHeader(file, lice, startTime);
    file.close();
	
	// Otvoranje na datotekata so prasanja i prevzemanje na soodvetnoto prasanje i negovite odgovori

    test.open("prasanja.txt", ios::in);
    while (getline(test, prasanje)) {
        for (int i = 0; i < prasanje.size(); i++) {
            if (prasanje[i] == ';') {
                cout << endl;
                i++;
            } else
                cout << prasanje[i];
        }
        cout << endl;

        odgovori_file.open(odgovori_filename.c_str(), ios::app);
        poeni += handleInput(brojnaprasanje, odgovori_file);
        odgovori_file.close();
        brojnaprasanje++;
    }

    test.close();

    int finalScore = score(poeni);
    string endTime = getTimestamp();

    file.open(filename.c_str(), ios::app);
    writeAnswerFileFooter(file, poeni, finalScore, endTime, odgovori_filename.c_str());
    file.close();

    cout << "\n\nVashata ocenka: " << finalScore << endl;

    answersTable();

    return 0;
}