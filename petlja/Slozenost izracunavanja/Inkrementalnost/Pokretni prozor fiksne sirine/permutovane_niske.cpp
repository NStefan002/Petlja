#include <iostream>
#include <vector>
#include <string>


using namespace std;

int brPodniski(const string s, const string x);

int main()
{
    string s, x;
    cin >> s >> x;

    cout << brPodniski(s, x) << endl;

    return 0;
}

int brPodniski(const string s, const string x)
{
    // prebrojavamo koliko puta se svaka cifra pojavljuje u x
    vector<int> brojaci(10, 0);
    for (int i = 0; x[i]; i++)
    {
        brojaci[x[i] - '0']++;
    }

    vector<int> trBrojaci(10, 0);

    for (int i = 0; x[i]; i++)
    {
        trBrojaci[s[i] - '0']++;
    }
   
    int brPodniski = 0;
    // provera za prvih x.length() karaktera
    /* Poredjenje dva vektora je definisano unutar klase vector
    i slozenosti je O(1) ako su vektori razlicitih duzina,
    u suprotnom O(n), gde je n duzina vektora 
    ZA VISE DETALJA POGLEDATI: https://en.cppreference.com/*/
    if (brojaci == trBrojaci)
    {
        brPodniski++;
    }

    /* U konkretnom slucaju, posto znamo da je duzina vektora 10,
    mozemo grubo oceniti da je poredjenje dva vektora konstantne
    slozenosti, pa je samim tim slozenost algoritma linearna u odnosu
    na duzinu niske s */

    int l, d;
    for (l = 1, d = x.length(); s[d]; l++, d++)
    {
        trBrojaci[s[l - 1] - '0']--;
        trBrojaci[s[d] - '0']++;

        if (brojaci == trBrojaci)
        {
            brPodniski++;
        }
    }
    
    return brPodniski;
}