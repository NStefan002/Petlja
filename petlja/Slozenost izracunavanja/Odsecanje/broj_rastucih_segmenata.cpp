#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // uint64_t da bi izbegao prekoracenje
    uint64_t brElemenataTrSegmenta = 1; // svaki segment mora imati bar jedan element
    uint64_t brRastucihSegmenata = 0;

    /* Broj nacina na koji se moze odabrati rastuci segment je:
        m * (m - 1) / 2, gde je m broj elemenata pronadjenog segmenta */
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            brElemenataTrSegmenta++;
        }
        else
        {
            brRastucihSegmenata += brElemenataTrSegmenta * (brElemenataTrSegmenta - 1) / 2;
            brElemenataTrSegmenta = 1;
        }
    }
    // dodavanje poslednjeg segmenta (ako je brElemenataTrSegmenta = 1 rezultat se ne menja)
    brRastucihSegmenata += brElemenataTrSegmenta * (brElemenataTrSegmenta - 1) / 2;
    
    cout << brRastucihSegmenata << endl;

    return 0;
}