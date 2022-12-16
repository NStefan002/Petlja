#include <iostream>
#include <vector>
#include <cctype>


using namespace std;

void ispisi(vector<pair<char, int>> &v);

int main()
{
    string prefiksniObilazak;
    cin >> prefiksniObilazak;

    // parovi su oblika <oznaka cvora, broj vidjenih grana iz tog cvora>
    vector<pair<char, int>> putDoLista;
    putDoLista.push_back({prefiksniObilazak[0], 0});
    
    for (int i = 1; i < prefiksniObilazak.length(); i++)
    {
        putDoLista.back().second++;
        putDoLista.push_back({prefiksniObilazak[i], 0});

        if (isupper(prefiksniObilazak[i]))
        {
            ispisi(putDoLista);
            // izbacujemo list
            putDoLista.pop_back();
            // izbacujemo sve cvorove kojima smo prosli sve potomke
            // (svaki cvor ima tacno 2 grane)
            while (putDoLista.back().second == 2)
            {
                putDoLista.pop_back();
            }
        }
    }
    
    return 0;
}

void ispisi(vector<pair<char, int>> &v)
{
    for (auto i : v)
    {
        cout << i.first;
    }
    cout << endl;
}