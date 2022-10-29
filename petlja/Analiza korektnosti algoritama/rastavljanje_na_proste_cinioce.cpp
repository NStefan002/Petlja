#include <iostream>
#include <cmath>

using namespace std;

bool jeste_prost(unsigned long long& n, unsigned long long& delilac);
void ispisi_proste_cinioce(unsigned long long n);

int main()
{   
    unsigned long long n;
    cin >> n;

    ispisi_proste_cinioce(n);

    return 0;
}

bool jeste_prost(unsigned long long& n, unsigned long long& delilac)
{
    while (delilac <= (unsigned long long)sqrt(n))
    {
        if (n % delilac == 0)
        {
            n /= delilac;
            return false;
        }
        delilac++;
    }
    
    return true;
}

void ispisi_proste_cinioce(unsigned long long n)
{
    unsigned long long delilac = 2;
    while (n != 1)
    {
        if (jeste_prost(n, delilac))
        {
            cout << n << ' ';
            break;
        }
        else
        {
            cout << delilac << ' ';
        }

        while (n % delilac == 0)
        {
            cout << delilac << ' ';
            n /= delilac;
        }
        delilac++;
    }   

    cout << endl;
}