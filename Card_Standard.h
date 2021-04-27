//
// Created by Paul Chelaru on 01/04/2021.
//

#ifndef OOP2_CARD_STANDARD_H
#define OOP2_CARD_STANDARD_H

#include "Card.h"

class Card_Standard : public Card {
protected:
    static int nrCarduriStandard;
    int limitaExtragere;
    double comisionDepasireLimita;
public:
    Card_Standard();

    Card_Standard(string, string, string, string, int, double, int, double);

    Card_Standard(Card_Standard &cardStandard);

    virtual ~Card_Standard();

    int getLimitaExtragere();

    void setLimitaExtragere(int limitaExtragere);

    double getComisionDepasireLimita();

    void setComisionDepasireLimita(double comisionDepasireLimita);

    void citire(istream &in);

    void afisare(ostream &out) const;

    Card_Standard &operator=(Card_Standard &cardStandard);

    static void nrCarduriStandardCreate();

    virtual void extragereBani(double sumaExtrasa);

    virtual string tipCard();
};

#endif //OOP2_CARD_STANDARD_H
