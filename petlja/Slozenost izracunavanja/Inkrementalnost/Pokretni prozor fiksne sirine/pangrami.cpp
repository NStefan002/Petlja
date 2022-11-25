#include <iostream>
#include <vector>


using namespace std;

bool imaPangram(const string s, int k);
bool imaSveKaraktere(vector<int>& v);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string linija;
    int k;

    getline(cin, linija);
    cin >> k;

    cout << (imaPangram(linija, k)? "da" : "ne") << endl;

    return 0;
}

bool imaSveKaraktere(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            return false;
        }
    }
    
    return true;
}

bool imaPangram(string s, int k)
{
    // ako je k manje od broja slova u abecedi, onda ne moze 
    // postojati podniska duzine k koja sadrzi sva slova abecede
    if (k < 26)
    {
        return false;
    }
    
    // brojimo koliko puta se koje slovo pojavilo u podniskama
    vector<int> brojaci(26, 0);

    // prebrojavanje prvih k karaktera
    for (int i = 0; i < k; i++)
    {
        brojaci[s[i] - 'a']++;
    }
    
    // pomeranje segmenta
    for (int i = k; s[i]; i++)
    {
        brojaci[s[i - k] - 'a']--;
        brojaci[s[i] - 'a']++;

        if (imaSveKaraktere(brojaci))
        {
            return true;
        }
    }
    
    return false;
}