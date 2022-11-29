#include <iostream>
#include <set>
// #include <map>


using namespace std;

// Jedno resenje:

/* Ovo resenje je iste slozenosti kao resenje koje sortira niz 
 i ispisuje ga. U praksi bi verovatno bilo bolje da se 
 niz rekonstruise u vektor (da bi kasnije mogli da ga koristimo
 ako je potrebno), ali ovde nema potrebe za tim. 
 
 Vremenska slozenost: O(nlog)
    - pri ucitavanju unosimo n brojeva i za svaki od njih
    je potrebno logaritamsko vreme da se unese u mapu
    - ispis je linearne slozenosti pa mozemo da ga zanemarimo */

/* int main()
{
    int n;
    cin >> n;

    // prebrojavamo koliko puta se koji broj pojavio
    // i na osnovu toga rekonstruisemo niz u neopadajucem poretku
    map<int, int> brojevi;    

    for (int i = 0; i < n; i++)
    {
        int br;
        cin >> br;
        brojevi[br]++;
    }
    
    // ispis je linearne slozenosti po broju unetih clanova niza
    for (auto p : brojevi)
    {
        while (p.second--)
        {
            cout << p.first << '\n';
        }
    }
    
    return 0;
} */

// Drugo resenje (malo bolje, jer je naredna struktura pogodnija za ovu vrstu problema):

int main() 
{
    int n;
    cin >> n;

    /* prolaskom kroz multiskup, kao i kroz skup,
    dobijamo sortirani poredak elemenata multiskupa */
    multiset<int> brojevi;

    for (int i = 0; i < n; i++)
    {
        int br;
        cin >> br;
        brojevi.insert(br);
    }
    
    for (auto b : brojevi)
    {
        cout << b << '\n';
    }
    
    return 0;
}