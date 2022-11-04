#include <iostream>
#include <cmath>

using namespace std;

bool jesteProst(unsigned x);

int main()
{
    unsigned n;
    cin >> n;

    cout << (jesteProst(n) ? "DA" : "NE") << endl; 

    return 0;
}

bool jesteProst(unsigned x)
{
    if (x % 2 == 0 || x == 1)
    {
        return false;
    }
    
    for (unsigned i = 3; i <= (unsigned)sqrt(x); i += 2)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    
    return true;
}