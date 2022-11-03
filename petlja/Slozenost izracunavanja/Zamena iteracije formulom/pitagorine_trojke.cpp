#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned n;
    cin >> n;

    // i krece od 3 jer je to najmanji element najmanje Pitagorina trojke
    // granice za a i b samo smanjuju koeficijent uz n^2, slozenost je idalje O(n^2)
    for (unsigned a = 3; 2 * a*a <= n*n; a++)
    {
        for (unsigned b = a + 1; a*a + b*b <= n*n; b++)
        {
            double c = sqrt(a*a + b*b);
            if (c - trunc(c) == 0.0)
            {
                cout << a << ' ' << b << ' ' << (unsigned)c << '\n'; 
            }
        }
    } 

    return 0;
}