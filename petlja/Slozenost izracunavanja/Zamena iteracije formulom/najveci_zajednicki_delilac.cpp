#include <iostream>


using namespace std;

unsigned NZD2(unsigned a, unsigned b);
unsigned NZD3(unsigned a, unsigned b, unsigned c);

int main()
{
    unsigned mravi, pcele, komarci;
    cin >> mravi >> pcele >> komarci;

    cout << NZD3(mravi, pcele, komarci) << endl;

    return 0;
}

unsigned NZD2(unsigned a, unsigned b)
{
    while (a != 0)
    {
        unsigned ost = b % a;
        b = a;
        a = ost;   
    }

    return b;
}

unsigned NZD3(unsigned a, unsigned b, unsigned c)
{   
    return NZD2(NZD2(a, b), c);
}