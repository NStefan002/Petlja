#include <iostream>


using namespace std;

bool mozeJedinica(string &s, int i);
void generisi(string &s, int i);

int main()
{
    string s;
    cin >> s;

    generisi(s, 0);

    return 0;
}

    /* Krecemo od prve pozicije u niski. Ukoliko je karakter na trenutnoj
    poziciji razlicit od tacke, funkcija ne treba da obradjuje taj karakter.
    Prvo generisemo sve moguce niske koje pocinju sa nulom (da bismo dobili 
    leksikografski rastuci rezultat). Ne moramo da proveravamo da li je moguce
    upisati nulu na dato mesto, za razliku od jedinice za koju moramo da vodimo
    racuna da se ne nalazi pored neke vec upisane jedinice. 
    
    Ovaj postupak mozemo zamisliti kao binarno stablo gde se svaki cvor grana na
    dva podstabla (jedno u kome je na prvoj slobodnoj poziciji upisana nula, a drugo
    gde je upisana jedinica). Kada se stigne do listova, odnosno kada je trenutna pozicija
    iza poslednjeg karaktera niske, niska se ispisuje i izlazi se iz rekurzije.
    
    Vizuelizacija pomenutog stabla na primeru "1...0" (knt - karakter nije tacka, d 0 - dodaj 0):
    1...0
      |--knt----- 1...0
                    |--d 0----- 10..0              
                    |             |--d 0----- 100.0
                    |             |             |--d 0----- 10000 
                    |             |                           |--knt----- 10000 (ispisi, izadji)
                    |             |             |--d 1----- 10010 (1 moze)
                    |             |                           |--knt----- 10010 (ispisi, izadji)
                    |             |
                    |             |--d 1------101.0 (1 moze)
                    |                           |--d 0----- 10100 
                    |                                         |--knt----- 10100 (ispisi, izadji) 
                    |                           |--d 1----- 10110 (1 ne moze, izadji)
                    |
                    |--d 1----- 11..0 (1 ne moze, izadji)

    Ispisi su redom: 10000, 10010, 10100 sto je upravo leksikografsko rastuci poredak.
     */
    
void generisi(string &s, int i)
{
    if (i == s.length()) 
    {
        cout << s << '\n';
        return;
    }

    if (s[i] != '.')
    {
        generisi(s, i + 1);
    }
    else 
    {
        // generisi sva podstabla koja pocinju nulom
        s[i] = '0';
        generisi(s, i + 1);

        // generisi sva podstabla koja pocinju jedinicom, ukoliko je to moguce
        if (mozeJedinica(s, i))
        {
            s[i] = '1';
            generisi(s, i + 1);
        }

        // vrati poziciju u originalno stanje, da bi bila dostupna drugim cvorovima stabla
        s[i] = '.';
    }
}

bool mozeJedinica(string &s, int i) 
{
    if (i == s.length() - 1)
    {
        return s[i - 1] != '1';
    }
    if (i == 0)
    {
        return s[i + 1] != '1';
    }
    return s[i - 1] != '1' && s[i + 1] != '1';
}