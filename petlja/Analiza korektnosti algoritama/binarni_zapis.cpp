#include <iostream>


using namespace std;

void binarni_zapis(unsigned n);

int main()
{
    unsigned n;
    cin >> n;

    binarni_zapis(n);

    return 0;
}

void binarni_zapis(unsigned n)
{
    unsigned mask = 1 << (8 * sizeof(int) - 1);
    while (mask)
    {
        if ((n & mask) != 0)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        
        mask >>= 1;
    }

    cout << '\n';
}