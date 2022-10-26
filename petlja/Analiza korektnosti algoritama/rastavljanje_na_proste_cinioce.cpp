#include <iostream>


using namespace std;

bool jeste_prost(unsigned long long n, unsigned long long najveci_delilac);
void ispisi_proste_cinioce(unsigned long long n);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    unsigned long long n;
    cin >> n;

    ispisi_proste_cinioce(n);

    return 0;
}

bool jeste_prost(unsigned long long n, unsigned long long najveci_delilac)
{
    for (unsigned long long i = najveci_delilac; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

void ispisi_proste_cinioce(unsigned long long n)
{
    unsigned long long delilac = 2;
    while (n != 1)
    {
        if (n % delilac == 0)
        {
            n /= delilac;
            cout << delilac << ' ';
        }
        else if (jeste_prost(n, delilac))
        {
            cout << n << ' ';
            break;
        }
        else
        {
            delilac++;
        }
    }   
    cout << '\n';
}