//
// Created by Paul Chelaru on 30/03/2021.
//
#include <iostream>
#include <utility>
#include "Card.h"

using namespace std;

int Card::nrCarduri = 0;

Card::Card() {
    nrCarduri++;
    nrCard = "";
    numeDetinator = "";
    dataExpirare = "";
    CVV = 0;
    credit = 0;
}

Card::Card(string nrCard, string numeDetinator, string prenumeDetinator, string dataExpirare, int CVV, double credit) {
    nrCarduri++;
    this->nrCard = nrCard;
    this->numeDetinator = numeDetinator;
    this->prenumeDetinator = prenumeDetinator;
    this->dataExpirare = dataExpirare;
    this->CVV = CVV;
    this->credit = credit;
}

Card::Card(Card &card) {
    nrCarduri++;
    this->nrCard = card.nrCard;
    this->numeDetinator = card.numeDetinator;
    this->prenumeDetinator = card.prenumeDetinator;
    this->dataExpirare = card.dataExpirare;
    this->CVV = card.CVV;
    this->credit = card.credit;
}

Card::~Card() {
    nrCard = "";
    numeDetinator = "";
    prenumeDetinator = "";
    dataExpirare = "";
    CVV = 0;
    credit = 0;
}

string Card::getNrCard() {
    return nrCard;
}

int Card::getNrCarduri() {
    return nrCarduri;
}

string &Card::getPrenumeDetinator(){
    return prenumeDetinator;
}

void Card::setPrenumeDetinator(string prenumeDetinator) {
    Card::prenumeDetinator = prenumeDetinator;
}

void Card::setNrCard(string nrCard) {
    this->nrCard = nrCard;
}

string Card::getNumeDetinator() {
    return numeDetinator;
}

void Card::setNumeDetinator(string numeDetinator) {
    this->numeDetinator = numeDetinator;
}

string Card::getDataExpirare() {
    return dataExpirare;
}

void Card::setDataExpirare(string dataExpirare) {
    this->dataExpirare = dataExpirare;
}

int Card::getCvv() {
    return CVV;
}

void Card::setCvv(int CVV) {
    this->CVV = CVV;
}

double Card::getCredit() {
    return credit;
}

void Card::setCredit(double credit) {
    this->credit = credit;
}

void Card::citire(istream &in) {
    cout << "Introduceti datele cardului: " << endl;
    cout << "Introduceti numarul cardului: ";
    in >> nrCard;
    cout << "Introduceti nume detinator: ";
    in >> numeDetinator;
    cout << "Introduceti prenumee detinator: ";
    in >> prenumeDetinator;
    cout << "Introduceti data expirarii: ";
    in >> dataExpirare;
    cout << "Introduceti CVV-ul: ";
    in >> CVV;
    cout << "Introduceti creditul cardului: ";
    in >> credit;
}

istream &operator>>(istream &in, Card &card) {
    card.citire(in);
    return in;
}

void Card::afisare(ostream &out) const {
    out << "Datele cardului dumneavoastra sunt urmatoarele: " << endl;
    out << "Numarul cardului este: " << nrCard << endl;
    out << "Introduceti nume detinator: " << numeDetinator << endl;
    out << "Introduceti prenume detinator: " << prenumeDetinator << endl;
    out << "Introduceti data expirarii: " << dataExpirare << endl;
    out << "Introduceti CVV-ul: " << CVV << endl;
    out << "Introduceti creditul cardului: " << credit << endl;
}

ostream &operator<<(ostream &out, const Card &card) {
    card.afisare(out);
    return out;
}

Card &Card::operator=(Card &card) {
    nrCard = card.nrCard;
    numeDetinator = card.numeDetinator;
    prenumeDetinator = card.prenumeDetinator;
    dataExpirare = card.dataExpirare;
    CVV = card.CVV;
    credit = card.credit;
    return *this;
}

void Card::nrCarduriCreate() {
    cout << "Numarul de carduri create este: " << nrCarduri << endl;
}
