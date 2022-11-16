#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX_IME 20


using namespace std;


struct Takmicar
{
    char ime[MAX_IME + 1];
    int brPoena;
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<Takmicar> takmicari(n);
    for (int i = 0; i < n; i++)
    {
        cin >> takmicari[i].ime >> takmicari[i].brPoena;
    }
    
    sort(begin(takmicari), end(takmicari), 
    [] (const Takmicar& t1, const Takmicar& t2)
    {
        if (t1.brPoena > t2.brPoena)
        {
            return true;
        }
        else if (t1.brPoena < t2.brPoena)
        {
            return false;
        }
        else 
        {
            return (strcmp(t1.ime, t2.ime) <= 0); // t1.ime <= t2.ime
        }
    });
    
    for (auto& t : takmicari)
    {
        cout << t.ime << ' ' << t.brPoena << '\n';
    }

    return 0;
}