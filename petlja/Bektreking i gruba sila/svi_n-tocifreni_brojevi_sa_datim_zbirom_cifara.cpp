#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

void generisi(vector<int> &cifre, int trazeniZbir, int brUpisanih, int brNeupisanih);
int zbirCifara(vector<int> &cifre, int brUpisanih);
void ispisi(vector<int> &v);

int main()
{
    int k, n;
    cin >> k >> n;

    vector<int>cifre(n);
    generisi(cifre, k, 0, n);

    return 0;
}

void generisi(vector<int> &cifre, int trazeniZbir, int brUpisanih, int brNeupisanih)
{
    if (brNeupisanih == 0)
    {
        ispisi(cifre);
        return;      
    }

    int faliDoTrazenogZbira = trazeniZbir - zbirCifara(cifre, brUpisanih);
    int najmanjaMoguca = max(faliDoTrazenogZbira - 9 * (brNeupisanih - 1), (brUpisanih == 0? 1 : 0));
    int najvecaMoguca = (faliDoTrazenogZbira < 9)? faliDoTrazenogZbira : 9;

    for (int i = najmanjaMoguca; i <= najvecaMoguca; i++)
    {
        cifre[brUpisanih] = i;
        generisi(cifre, trazeniZbir, brUpisanih + 1, brNeupisanih - 1);
    }
}

int zbirCifara(vector<int> &cifre, int brUpisanih)
{
    int zbir = 0;
    for (int i = 0; i < brUpisanih; i++)
    {
        zbir += cifre[i];
    }
    return zbir; 
}

void ispisi(vector<int> &v)
{
    for (auto x : v)
    {
        cout << x;
    }
    cout << '\n';
}