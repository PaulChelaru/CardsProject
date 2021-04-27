//
// Created by Paul Chelaru on 01/04/2021.
//

#ifndef OOP2_CARD_PREMIUM_H
#define OOP2_CARD_PREMIUM_H

#include "Card_Standard.h"

class Card_Premium : public Card_Standard {
    static int nrCarduriPremium;
    double cashback;
public:
    Card_Premium();

    Card_Premium(string, string, string, string, int, double, int, double, double);

    Card_Premium(Card_Premium &cardPremium);

    ~Card_Premium();

    static void nrCarduriPremiumCreate();

    double getCashback();

    void setCashback(double cashback);

    void citire(istream &in);

    void afisare(ostream &out) const;

    Card_Premium &operator=(Card_Premium &cardPremium);

    void extragereBani(double sumaExtrasa);

    string tipCard();
};

#endif //OOP2_CARD_PREMIUM_H
