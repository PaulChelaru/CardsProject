//
// Created by Paul Chelaru on 30/03/2021.
//

#include <string>
#include "Card.h"
#include "Card_Standard.h"

int Card_Standard::nrCarduriStandard = 0;

Card_Standard::Card_Standard(string nrCard, string numeDetinator, string prenumeDetinator, string dataExpirare,
                             int CVV, double credit, int limitaExtragere, double comisionDepasireLimita) :
        Card(nrCard, numeDetinator, prenumeDetinator, dataExpirare, CVV, credit) {
    nrCarduriStandard++;
    this->limitaExtragere = limitaExtragere;
    this->comisionDepasireLimita = comisionDepasireLimita;
}

Card_Standard::Card_Standard() : Card() {
    nrCarduriStandard++;
    limitaExtragere = 0;
    comisionDepasireLimita = 0;
}

Card_Standard::Card_Standard(Card_Standard &cardStandard) : Card(cardStandard) {
    nrCarduriStandard++;
    limitaExtragere = cardStandard.limitaExtragere;
    comisionDepasireLimita = cardStandard.comisionDepasireLimita;
}

Card_Standard::~Card_Standard() {
    nrCard = "";
    numeDetinator = "";
    prenumeDetinator = "";
    dataExpirare = "";
    CVV = 0;
    credit = 0;
    limitaExtragere = 0;
    comisionDepasireLimita = 0;
}

int Card_Standard::getLimitaExtragere() {
    return limitaExtragere;
}

void Card_Standard::setLimitaExtragere(int limitaExtragere) {
    this->limitaExtragere = limitaExtragere;
}

double Card_Standard::getComisionDepasireLimita() {
    return comisionDepasireLimita;
}

void Card_Standard::setComisionDepasireLimita(double comisionDepasireLimita) {
    this->comisionDepasireLimita = comisionDepasireLimita;
}

void Card_Standard::citire(istream &in) {
    Card::citire(in);
    cout << "Introduceti limita de extragere: ";
    in >> limitaExtragere;
    cout << "Introduceti comisionul de depasire al limitei impuse: ";
    in >> comisionDepasireLimita;
}

void Card_Standard::afisare(ostream &out) const {
    Card::afisare(out);
    out << "Limita de extragere este: " << limitaExtragere << endl;
    out << "Comosionul pentru depasirea limitei de extragere este: " << comisionDepasireLimita << endl;
}

Card_Standard &Card_Standard::operator=(Card_Standard &cardStandard) {
    Card::operator=(cardStandard);
    comisionDepasireLimita = cardStandard.comisionDepasireLimita;
    limitaExtragere = cardStandard.limitaExtragere;
    return *this;
}

void Card_Standard::nrCarduriStandardCreate() {
    cout << "Numarul de carduri standard create este: " << nrCarduriStandard << endl;
}

void Card_Standard::extragereBani(double sumaExtrasa) {
    if (sumaExtrasa > credit)
        cout << "Nu aveti suficient credit pentru a extrage suma dorita." << endl;
    else {
        if (sumaExtrasa > limitaExtragere) {
            cout << "Pentru ca suma de extragere este mai mare decat limita de extragere"
                    " veti suporta un comision de " << comisionDepasireLimita << "%." << endl;
            cout << "Continuati? [Y / N]: ";
            char raspuns;
            cin >> raspuns;

            if(raspuns == 'Y') {
                cout << "Ati extras suma de: " << sumaExtrasa << endl;
                credit -= sumaExtrasa;
                credit -= comisionDepasireLimita/100 * sumaExtrasa;
                cout << "Creditul dumneavoastra curent este: " << credit << endl;
            } else {
                cout << "Tranzactia a fost refuzata!";
            }
        } else {
            cout << "Ati extras suma de: " << sumaExtrasa << endl;
            credit -= sumaExtrasa;
            cout << "Creditul dumneavoastra curent este: " << credit << endl;
        }
    }
}

string Card_Standard::tipCard() {
    return "standard";
}
