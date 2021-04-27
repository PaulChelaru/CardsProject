# CardsProject
<h2> Cerinte comune tuturor temelor: </h2>
<ul>
<li>Toate clasele vor conține obligatoriu constructori de inițializare, parametrizați și de copiere; destructor; operatorii „=”, „>>”„ <<” supraîncărcați corespunzător, moșteniri & encapsulare</li>
<li>Clasele derivate trebuie sa contina constructori parametrizati (prin care sa se evidentieze transmiterea parametrilor catre constructorul din clasa de baza) si destructori.</li>
<li>În fiecare proiect vor fi ilustrate conceptele de upcasting, downcasting, funcții virtuale(pure–unde se consideră mai natural)</li>
<li>Utilizarea de variabile și de funcții statice. </li>
<li>Citirea informațiilor complete a n obiecte, memorarea și afișarea acestora</li>
<li>Meniu interactiv</li>
<ul>

<h2> Tema Cardurilor </h2>
<p>Se dau clasele: </p>
<ul>
 <li>Card (string nrCard, string NumeDetinator, string data_expirare, int CVV, double credit)[cvv=cele 3 cifre de pe spatele cardului)</li>
 <li>Card_standard (int limitaExtragere, double comisionDepasireLimita) : Card</li>
 <li>Card premium (double cashback) : Card_Standard</li>
</ul>
<p> Sa permiteti printr-o metoda sa extrageti bani de pe un card. Sa se verifice ca aceasta suma sa nu fiemai mare decat creditul. Sa se modifice creditul la extragere in functie de card standard saupremium. Daca depaseste limita cardului standard atunci se aplica comisionul pentru diferenta debani. Daca se extrage de pe un card premium sa primeasca inapoi cashback/100 * suma retrasa. </p>
