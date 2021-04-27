# CardsProject
Cerințe comune tuturor temelor:
1.Toate clasele vor conține obligatoriu constructori de inițializare, parametrizați și de copiere; destructor; operatorii „=”, „>>”„ <<” supraîncărcați corespunzător, moșteniri & encapsulare
2.Clasele derivate trebuie sa contina constructori parametrizati (prin care sa se evidentieze transmiterea parametrilor catre constructorul din clasa de baza) si destructori.
3.În fiecare proiect vor fi ilustrate conceptele de upcasting, downcasting, funcții virtuale(pure–unde se consideră mai natural)
4.Utilizarea de variabile și de funcții statice – 1p5.Citirea informațiilor complete a n obiecte, memorarea și afișarea acestora –
5.Meniu interactiv

Se dau clasele:
-Card (string nrCard, string NumeDetinator, string data_expirare, int CVV, double credit)[cvv=cele 3 cifre de pe spatele cardului)
-Card_standard (int limitaExtragere, double comisionDepasireLimita) : Card
-Card premium (double cashback) : Card_Standard
Sa permiteti printr-o metoda sa extrageti bani de pe un card. Sa se verifice ca aceasta suma sa nu fiemai mare decat creditul. Sa se modifice creditul la extragere in functie de card standard saupremium. Daca depaseste limita cardului standard atunci se aplica comisionul pentru diferenta debani. Daca se extrage de pe un card premium sa primeasca inapoi cashback/100 * suma retrasa.
