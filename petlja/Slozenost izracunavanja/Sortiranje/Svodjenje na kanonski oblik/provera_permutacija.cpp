#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void ucitavanje(vector<int>& niz1, vector<int>& niz2);
bool jestePermutacija(vector<int>& niz1, vector<int>& niz2);

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> niz1, niz2;
    ucitavanje(niz1, niz2);

    sort(begin(niz1), end(niz1));
    sort(begin(niz2), end(niz2));

    cout << (jestePermutacija(niz1, niz2)? "da" : "ne") << endl;

    return 0;
}

void ucitavanje(vector<int>& niz1, vector<int>& niz2)
{
    int n1;
    cin >> n1;

    niz1 = vector<int>(n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> niz1[i];
    }
    
    int n2;
    cin >> n2;

    niz2 = vector<int>(n2);
    for (int i = 0; i < n2; i++)
    {
        cin >> niz2[i];
    }
}

bool jestePermutacija(vector<int>& niz1, vector<int>& niz2)
{
    if (niz1.size() != niz2.size())
    {
        return false;
    }
    
    for (int i = 0; i < niz1.size(); i++)
    {
        if (niz1[i] != niz2[i])
        {
            return false;
        }
    }
    
    return true;
}