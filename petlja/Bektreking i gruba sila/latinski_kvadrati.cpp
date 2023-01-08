#include <iostream>
#include <vector>


using namespace std;

void generisi(vector<string> &kvadrat, int n, int i, int j);
bool ispravnoUpisano(vector<string> &kvadrat, int n, int i, int j);
void ispisi(vector<string> &kvadrat);

int main()
{
    int n;
    cin >> n;

    vector<string> kvadrat(n);
    for (int i = 0; i < n; i++)
    {
        cin >> kvadrat[i];
    }
    
    generisi(kvadrat, n, 0, 0);

    return 0;
}

void generisi(vector<string> &kvadrat, int n, int i, int j)
{
    if (j == n)
    {
        j = 0;
        i++;
    }
    
    if (i == n)
    {
        ispisi(kvadrat);
        return;
    }
    
    if (kvadrat[i][j] != '0')
    {
        generisi(kvadrat, n, i, j + 1);
        return;
    }
    
    char charN = '0' + n;
    for (char broj = '1'; broj <= charN; broj++)
    {
        kvadrat[i][j] = broj;
        if (ispravnoUpisano(kvadrat, n, i, j))
        {
            generisi(kvadrat, n, i, j + 1);   
        }
    }
    kvadrat[i][j] = '0';
}

bool ispravnoUpisano(vector<string> &kvadrat, int n, int i, int j)
{
    for (int v = 0; v < n; v++)
    {
        if (kvadrat[v][j] == kvadrat[i][j] && v != i)
        {
            return false;
        }
    }
    
    for (int k = 0; k < n; k++)
    {
        if (kvadrat[i][k] == kvadrat[i][j] && k != j)
        {
            return false;
        }
    }

    return true;
}

void ispisi(vector<string> &kvadrat)
{
    for (auto v : kvadrat)
    {
        cout << v << ' ';
        cout << '\n';
    }
    cout << '\n';
}