#include <iostream>


using namespace std;

int main()
{
    int n;
    cin >> n;

    int prethodniElement;
    cin >> prethodniElement;

    int ukupanBrSegmenata = 0;
    // jedan element cini segment
    int trBrSegmenata = 1;

    for (int i = 1; i < n; i++)
    {
        int trenutniElement;
        cin >> trenutniElement;

        ukupanBrSegmenata += trBrSegmenata;
        if (trenutniElement % 2 == prethodniElement % 2)
        {
            trBrSegmenata++;
        }
        else
        {
            trBrSegmenata = 1;
        }

        prethodniElement = trenutniElement;
    }
    // obrada poslednjeg prolaza
    ukupanBrSegmenata += trBrSegmenata;
    
    cout << ukupanBrSegmenata << endl;

    return 0;
}