//
// Created by Paul Chelaru on 30/03/2021.
//

#include "Card_Premium.h"
#include "Card_Standard.h"
#include <iostream>
#include <utility>

using namespace std;

int Card_Premium::nrCarduriPremium = 0;

void Card_Premium::nrCarduriPremiumCreate() {
    cout << "Numarul de carduri premium este: " << nrCarduriPremium << endl;
}

Card_Premium::Card_Premium() : Card_Standard() {
    Card_Standard::nrCarduriStandard--;
    nrCarduriPremium++;
    this->cashback = 0;
}

Card_Premium::Card_Premium(string nrCard, string numeDetinator, string prenumeDetinator,
                           string dataExpirare, int CVV, double credit, int limitaExtragere,
                           double comisionDepasireLimita, double cashback)
        : Card_Standard(nrCard, numeDetinator, prenumeDetinator, dataExpirare, CVV, credit, limitaExtragere,
                        comisionDepasireLimita) {
    this->cashback = cashback;
    Card_Standard::nrCarduriStandard--;
    nrCarduriPremium++;
}

Card_Premium::Card_Premium(Card_Premium &cardPremium) : Card_Standard(cardPremium) {
    Card_Standard::nrCarduriStandard--;
    nrCarduriPremium++;
    cashback = cardPremium.cashback;
}

Card_Premium::~Card_Premium() {
    cashback = 0;
}

double Card_Premium::getCashback() {
    return cashback;
}

void Card_Premium::setCashback(double cashback) {
    this->cashback = cashback;
}

void Card_Premium::citire(istream &in) {
    Card_Standard::citire(in);
    cout << "Introduceti cat % cashback va avea cardul: ";
    in >> cashback;
}

void Card_Premium::afisare(ostream &out) const {
    Card_Standard::afisare(out);
    out << "Cardul are " << cashback << "% casback.";
}

Card_Premium &Card_Premium::operator=(Card_Premium &cardPremium) {
    Card_Standard::operator=(cardPremium);
    this->cashback = cardPremium.cashback;
    return *this;
}

void Card_Premium::extragereBani(double sumaExtrasa) {
    double copieCredit = credit;
    Card_Standard::extragereBani(sumaExtrasa);
    if (credit != copieCredit) {
        cout << "A fost aplicat un cashback de: " << cashback << "% = " << cashback / 100 * sumaExtrasa << endl;
        credit += cashback / 100 * sumaExtrasa;
        cout << "Creditul dumneavostra dupa aplicarea cashback-ului este: " << credit << endl;
    }
}

string Card_Premium::tipCard() {
    return "premium";
}
