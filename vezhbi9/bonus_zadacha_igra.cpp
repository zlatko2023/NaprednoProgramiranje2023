#include <iostream>
using namespace std;

char tabla[3][3] = {
    { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ',' ',' ' }
};

char igrac = 'X';
string igrac1Ime, igrac2Ime, prikazanoIme;

void kreirajTabla() {
    system("CLS");
    cout<<"X/O"<<endl;
    cout<<igrac1Ime<<" (X) - "<<igrac2Ime<<" (O)"<<endl<<endl;  
    cout<<"     |     |     "<<endl;
    cout<<"  "<<(tabla[0][0] == 'X' || tabla[0][0] == 'O' ? tabla[0][0] : ' ')<<"  |  "<<(tabla[0][1] == 'X' || tabla[0][1] == 'O' ? tabla[0][1] : ' ')<<"  |  "<<(tabla[0][2] == 'X' || tabla[0][2] == 'O' ? tabla[0][2] : ' ')<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<(tabla[1][0] == 'X' || tabla[1][0] == 'O' ? tabla[1][0] : ' ')<<"  |  "<<(tabla[1][1] == 'X' || tabla[1][1] == 'O' ? tabla[1][1] : ' ')<<"  |  "<<(tabla[1][2] == 'X' || tabla[1][2] == 'O' ? tabla[1][2] : ' ')<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<(tabla[2][0] == 'X' || tabla[2][0] == 'O' ? tabla[2][0] : ' ')<<"  |  "<<(tabla[2][1] == 'X' || tabla[2][1] == 'O' ? tabla[2][1] : ' ')<<"  |  "<<(tabla[2][2] == 'X' || tabla[2][2] == 'O' ? tabla[2][2] : ' ')<<endl;
    cout<<"     |     |     "<<endl<<endl;
}

void vnesiPole() {
    int red, kol;
    cout<<prikazanoIme<<", vnesi broj na red (1-3): ";
    cin>>red;
    cout<<prikazanoIme<<", vnesi broj na kolona (1-3): ";
    cin>>kol;
    red--;
    kol--;
    if (red < 0 || red > 2 || kol < 0 || kol > 2) {
        cout<<"Nevalidno pole! Probaj povtorno."<<endl;
        vnesiPole();
    } else if (tabla[red][kol] == 'X' || tabla[red][kol] == 'O') {
        cout<<"Poleto e vekje ispolneto! Probaj povtorno."<<endl;
        vnesiPole();
    } else {
        tabla[red][kol] = igrac;
    }
}

bool krajIgra() {
    
    for (int i = 0; i < 3; i++) {
        if (tabla[i][0] == tabla[i][1] && tabla[i][1] == tabla[i][2] && tabla[i][0] != ' ') {
            return true;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (tabla[0][i] == tabla[1][i] && tabla[1][i] == tabla[2][i] && tabla[0][i] != ' ') {
            return true;
        }
    }
    
    if (tabla[0][0] == tabla[1][1] && tabla[1][1] == tabla[2][2] && tabla[0][0] != ' ') {
        return true;
    }
    if (tabla[0][2] == tabla[1][1] && tabla[1][1] == tabla[2][0] && tabla[0][2] != ' ') {
        return true;
    }

    bool praznoMesto = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabla[i][j] == ' ') {
                praznoMesto = true;
                break;
            }
        }
    }
    if (!praznoMesto) {
        return true;
    }
    return false;
}

void promeniIgrac() {
    if (igrac == 'X') {
        igrac = 'O';
        prikazanoIme = igrac2Ime;
    } else {
        igrac = 'X';
        prikazanoIme = igrac1Ime;
    }
}

int main() {
    cout<<"Vnesi ime na igrachot (X): ";
    cin>>igrac1Ime;
    prikazanoIme = igrac1Ime;
    cout<<"Vnesi ime na igrachot (O): ";
    cin>>igrac2Ime;

    while (!krajIgra()) {
        kreirajTabla();
        vnesiPole();
        promeniIgrac();
    }
    kreirajTabla();
    if (krajIgra() && !igrac) {
        cout<<"Neresheno!"<<endl;
    } else {
        promeniIgrac();
        cout<<"Chestitki!\n"<<prikazanoIme<<" pobedi!"<<endl;
    }
    return 0;
}