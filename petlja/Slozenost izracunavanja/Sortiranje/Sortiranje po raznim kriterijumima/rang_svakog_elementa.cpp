#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


struct Ucenik
{
    string ime;
    int brPoena;
    int redniBroj;
    int prvobitniIndex; // za ispis
};

/* Vremenska slozenost: 3*n + 2*nlogn = O(nlogn)
   Prostorna slozenost: O(n) */

int main()
{
    int n;
    cin >> n;

    vector<Ucenik> ucenici(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ucenici[i].ime >> ucenici[i].brPoena;
        ucenici[i].prvobitniIndex = i;
    }
    
    sort(begin(ucenici), end(ucenici),
    [] (const Ucenik& u1, const Ucenik& u2)
    {
        return u1.brPoena > u2.brPoena;
    });

    for (int i = 0; i < n; i++)
    {
        ucenici[i].redniBroj = i + 1;
    }
    
    // vracanje u prvobitni redosled zbog formata ispisa
    sort(begin(ucenici), end(ucenici),
    [] (const Ucenik& u1, const Ucenik& u2)
    {
        return u1.prvobitniIndex < u2.prvobitniIndex;
    });
    
    for (auto& u : ucenici)
    {
        cout << u.ime << ' ' << u.redniBroj << '\n';
    }
    
    return 0;
}