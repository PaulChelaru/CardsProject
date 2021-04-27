#include <iostream>
#include <vector>
#include "Card.h"
#include "Card_Premium.h"
#include "Card_Standard.h"

using namespace std;

void menu_output() {
    cout << "\n Chelaru paul 134 - Proiect2 - Nume proiect: Tema12 \n";
    cout << "\n\t MENIU:";
    cout << "\n===========================================\n";
    cout << "\n";
    cout << "1. Afisare informatii despre cashback-ul celor n carduri. ";
    cout << "\n";
    cout << "2. Extragere bani de pe unul din cele n carduri.";
    cout << "\n";
    cout << "3. Afiseaza numarul de carduri standard create.";
    cout << "\n";
    cout << "4. Afiseaza numarul de carduri premium create.";
    cout << "\n";
    cout << "5. Afiseaza numarul de carduri create in total.";
    cout << "\n";
    cout << "6. Afiseaza toate cardurile.";
    cout << "\n";
    cout << "0. Iesire.";
    cout << "\n";
}

void tip(Card *&card, int &i) {
    string tipCard;
    cout << "\n";
    cout << "Introduceti tipul cardului " << i + 1 << " [standard / premium]: ";
    cin >> tipCard;
    try {
        if (tipCard == "standard") {
            card = new Card_Standard;
            cin >> *card;
            i++;
        } else if (tipCard == "premium") {
            card = new Card_Premium;
            cin >> *card;
            i++;
        } else throw 10;
    } catch (int j) {
        cout << "Nu ati introdus un tip de card valid.\n ";
    }
}

void afisareCarduri(Card **cards, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Cardul " << i + 1 << " este: " << endl;
        cout << *cards[i] << endl << endl;
    }
}

void menu() {
    int option;
    option = 0;

    Card **cards;
    cout << "Introduceti numarul de carduri: ";
    int n;
    cin >> n;
    cards = new Card *[n];
    for (int i = 0; i < n;)
        tip(cards[i], i);

    cout << endl;
    cout << "Cardurile salvate sunt: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Cardul " << i + 1 << " este:" << endl;
        cout << *cards[i] << endl;
        cout << "--------------------------\n";
    }

    do {
        menu_output();

        cout << "\nIntroduceti numarul actiunii: ";
        cin >> option;


        if (option == 1) {
            for (int i = 0; i < n; i++) {
                Card_Premium *cardPremium = dynamic_cast<Card_Premium *>(cards[i]);
                if (cardPremium)
                    cout << "Cashback-ul pentru cardul " << i + 1
                         << " este: " << cardPremium->getCashback();
                else
                    cout << "Cardul " << i + 1 << " nu este un card premium, "
                                                  "prin urmare nu are cashback." << endl;
            }
        }
        if (option == 2) {
            cout << "Introduceti numarul cardului de pe care doriti sa extrageti bani (nu mai mare de  "
                 << n << ").";
            int nrCard, suma;
            cin >> nrCard;
            Card_Standard *card = dynamic_cast<Card_Standard *>(cards[nrCard - 1]);
            cout << "Creditul cardului " << nrCard << " este: " << card->getCredit() << endl;
            cout << "Limita de extragere a cardului " << nrCard << " este: " << card->getLimitaExtragere() << endl;
            cout << "Introduceti suma pe care doriti sa o extrageti: ";
            cin >> suma;
            card->extragereBani(suma);
        }
        if (option == 3) {
            Card_Standard::nrCarduriStandardCreate();
        }
        if (option == 4) {
            Card_Premium::nrCarduriPremiumCreate();
        }
        if (option == 5) {
            Card::nrCarduriCreate();
        }
        if (option == 6) {
            afisareCarduri(cards, n);
        }
        if (option == 0) {
            cout << "\nEXIT!\n";
        }
        if (option < 0 || option > 6) {
            cout << "\nSelectie invalida\n";
        }
        cout << "\n";
    } while (option != 0);
}

int main() {
    menu();
    return 0;
}