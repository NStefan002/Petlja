#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Ucenik
{
    vector<int> ocene;
    int zbir_ocena; // svejedno je da li cemo da poredimo
    // ucenike po proseku ili po zbiru ocena, jer svi imaju isti broj ocena
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int u, o;
    cin >> u >> o;

    vector<Ucenik> ucenici(u);

    for (int i = 0; i < u; i++)
    {
        ucenici[i].ocene.resize(o);
        ucenici[i].zbir_ocena = 0;

        for (int j = 0; j < o; j++)
        {
            cin >> ucenici[i].ocene[j];
            ucenici[i].zbir_ocena += ucenici[i].ocene[j];
        }   
    }
    
    stable_sort(begin(ucenici), end(ucenici),
    [] (const Ucenik& u1, const Ucenik& u2)
    {
        return u1.zbir_ocena > u2.zbir_ocena;
    });

    for (auto& u : ucenici)
    {
        for (auto o : u.ocene)
        {
            cout << o << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}