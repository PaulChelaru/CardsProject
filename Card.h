//
// Created by Paul Chelaru on 30/03/2021.
//
#include <iostream>

using namespace std;

#ifndef OOP2_CARD_H
#define OOP2_CARD_H

class Card {
protected:
    static int nrCarduri;
    string nrCard;
    string numeDetinator;
    string prenumeDetinator;
    string dataExpirare;
    int CVV;
    double credit;
public:
    Card();

    Card(string, string, string, string, int, double);

    Card(Card &card);

    virtual ~Card();

    string getNrCard();

    void setNrCard(string nrCard);

    string getNumeDetinator();

    static int getNrCarduri();

    string &getPrenumeDetinator();

    void setPrenumeDetinator(string prenumeDetinator);

    void setNumeDetinator(string numeDetinator);

    string getDataExpirare();

    void setDataExpirare(string dataExpirare);

    int getCvv();

    void setCvv(int CVV);

    double getCredit();

    void setCredit(double credit);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out) const;

    friend istream &operator>>(istream &in, Card &card);

    friend ostream &operator<<(ostream &out, const Card &card);

    Card &operator=(Card &card);

    static void nrCarduriCreate();
};

#endif //OOP2_CARD_H
