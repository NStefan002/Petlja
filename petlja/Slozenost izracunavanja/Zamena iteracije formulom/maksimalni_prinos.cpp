#include <iostream>


using namespace std;


unsigned long long maxPovrsina(unsigned long long a, unsigned long long b, unsigned long long c);

int main()
{
    unsigned long long a, b, c;
    cin >> a >> b >> c;

    
    

    cout << maxPovrsina(a, b, c) << '\n';

    return 0;
}

unsigned long long maxPovrsina(unsigned long long a, unsigned long long b, unsigned long long c)
{
    /* 
        a i b treba da budu sto priblizniji po vrednosti, jer se povrsina povecava
        ako se figura dimenzija axb priblizava kvadratu (ako je a+b konstantno)

        [npr. ako uzmemo da je a + b = 10, i ispisemo sve moguce kombinacije a i b
         dobicemo da je 1*9 < 2*8 < 3*7 < 4*6 < 5*5. U opstim brojevima to mozemo 
         izraziti na sledeci nacin: 
         1*(n-1), 2*(n-2), ... n/2 * n/2 (odnosno (n-1)/2 * ((n-1)/2 + 1) za neparno n),
         gde je n = a + b]
    */

    if (a > b)
    {
        if (c < a - b)
        {
            b += c;
            c = 0;
        }
        else
        {
            c -= (a - b);
            b += (a - b);
        }
    }
    else
    {
        if (c < b - a)
        {
            a += c;
            c = 0;
        }
        else
        {
            c -= (b - a);
            a += (b - a);
        }
    }
    
    if (c % 2 == 0)
    {
        a += c/2;
        b += c/2;
    }
    else
    {
        c--;
        a += c/2 + 1;
        b += c/2;
    }

    
    return a * b;
}