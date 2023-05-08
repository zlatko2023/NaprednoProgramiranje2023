// Zlatko Markovski INKI937
//NP-lab.04
#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define CARDS 52
#define FACES 13

// card structure definition
struct card {
    const char * face; // define pointer face
    const char * suit; // define pointer suit
}; // end struct card

typedef struct card Card; // new type name for struct card

// prototypes
void fillDeck(Card *
    const wDeck,
        const char * wFace[],
            const char * wSuit[]);
void shuffle(Card *
    const wDeck);
void deal(const Card *
    const wDeck);

int main(void) {
    Card deck[CARDS]; // define array of Cards

    // sto se pravi vo ovoj red ?    
    // ODGOVOR: face e niza od stringovi, koja sodrzhi 13 elementi(broevi koi gi ima vo eden shpil karti). const char * kazhuva deka sekoj element e pokazhuvach konstanten karakter 
    const char * face[] = {
        "Ace",
        "Deuce",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
        "Ten",
        "Jack",
        "Queen",
        "King"
    };

    // sto se pravi vo ovoj red ?
    // ODGOVOR: suit e niza od stringovi, koja sodrzhi 4 elementi(znaci koi gi ima vo eden shpil karti). const char * kazhuva deka sekoj element e pokazhuvach konstanten karakter 
    const char * suit[] = {
        "Hearts",
        "Diamonds",
        "Clubs",
        "Spades"
    };

    srand(time(NULL)); // sto e ovaa naredba ? --- ODGOVOR: dobivame random broj vrz osnova na momentalnoto vreme

    fillDeck(deck, face, suit);
    shuffle(deck);
    deal(deck);
} // end main

// place strings into Card structures
void fillDeck(Card *
    const wDeck,
        const char * wFace[],
            const char * wSuit[]) {
    size_t i;

    // loop through wDeck
    for (i = 0; i < CARDS; ++i) {
        wDeck[i].face = wFace[i % FACES];
        wDeck[i].suit = wSuit[i / FACES];
    } // end for
} // end function fillDeck

// shuffle cards
void shuffle(Card *
    const wDeck) {
    size_t i; // sto e ovaa promenliva ? 
              //--- ODGOVOR: promenlivata i so tipot size_t se koristi za pretstavuvanje na goleminata na objektot vo memorijata

    size_t j; // sto e ovaa promenliva i vo koi vrednosti se dvizi ? vidi kod  
              // --- ODGOVOR: promenlivata j so tipot size_t se koristi za pretstavuvanje na goleminata na objektot vo memorijata.
              // ovaa proemnliva se dvizhi pomegju 0 i CARDS-1
    
    Card temp; // define temporary structure for swapping Cards

    // loop thr
    for (i = 0; i < CARDS; ++i) {
        j = rand() % CARDS; // 
        temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    } // end for
} // end function shuffle

// deal cards
void deal(const Card *
    const wDeck) {
    size_t i; // counter

    // loop through wDeck
    for (i = 0; i < CARDS; ++i) {
        printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit,
            (i + 1) % 4 ? "  " : "\n");
    } // end for
} // end function deal
