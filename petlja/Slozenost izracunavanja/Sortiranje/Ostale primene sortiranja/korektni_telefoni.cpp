#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;

bool jesteKorektan(vector<string>& brojevi);

int main()
{
    int n;
    cin >> n;

    vector<string> brojevi(n);
    for (int i = 0; i < n; i++)
    {
        cin >> brojevi[i];
    }
    
    sort(begin(brojevi), end(brojevi));   

    cout << (jesteKorektan(brojevi)? "da" : "ne") << endl;

    return 0;
}

bool jesteKorektan(vector<string>& brojevi)
{
    for (int i = 1; i < brojevi.size(); i++)
    {   
        if (brojevi[i].substr(0, brojevi[i - 1].length()) == brojevi[i - 1])
        {
            return false;
        }
    }

    return true;
}