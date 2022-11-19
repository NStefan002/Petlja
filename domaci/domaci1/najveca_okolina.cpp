#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Vremenska slozenost: O(nlogn)
   Prostorna slozenost: O(n) */

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, delta;
    cin >> n >> delta;
    
    vector<int> elementiSkupa(n);
    for (int i = 0; i < n; i++)
    {
        cin >> elementiSkupa[i];
    }
    
    sort(begin(elementiSkupa), end(elementiSkupa));

    /*
    d = 4 
    4 -6  3 12  1 -4  9

    l
    e
   -6 -4  1  3  4  9 12
       d  
    */

    int maxElement = elementiSkupa[0], maxOkolina = 1; // okolina elementa uvek sadrzi bar taj element 
    int l = 0, e = 0, d = 0;  // e je trenutni element ciju okolinu ispitujemo u granicama [l, d]

    while (e < n) // slozenost je O(n) jer se nijedan brojac ne vraca unazad
    {
        // pomeramo levu granicu u odnosu na trenutni element
        while (abs(elementiSkupa[e] - elementiSkupa[l]) > delta && l < e)
        {
            l++;
        }

        // pomeramo desnu granicu u odnosu na trenutni element
        while (abs(elementiSkupa[e] - elementiSkupa[d + 1]) <= delta && d < n - 1)
        {
            d++;
        }

        int trOkolina = d - l + 1;
        if (maxOkolina < trOkolina)
        {
            maxOkolina = trOkolina;
            maxElement = elementiSkupa[e];
        }

        e++;
    }

    cout << maxElement << " " << maxOkolina << endl;

    return 0;
}