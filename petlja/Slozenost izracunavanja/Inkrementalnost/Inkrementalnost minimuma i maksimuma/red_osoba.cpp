#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int brOsoba = 1;    // prvu osobu sigurno vidi 
    int visina;
    cin >> visina;
    int maxVisina = visina;   // maxVisina inicijalizujemo na visinu prve osobe u redu

    for (int i = 1; i < n; i++)
    {
        cin >> visina;
        if (visina > maxVisina)
        {
            brOsoba++;
            maxVisina = visina;
        }
    }
    
    cout << brOsoba << endl;

    return 0;
}