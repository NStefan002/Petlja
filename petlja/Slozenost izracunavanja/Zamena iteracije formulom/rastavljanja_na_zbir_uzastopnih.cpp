#include <iostream>


using namespace std;

int main()
{
    unsigned n;
    cin >> n;

    /*
        a_0 je prvi sabirak, a k je broj sabiraka:
        a_0 + (a_0 + 1) + ... + (a_0 + (k - 1)) = n
        k*a_0 + k*(k - 1)/2 = n

        Ako fiksiramo k, dobijamo linearnu jednacinu po a_0 (sto je efikasnije,
        nego da fiksiramo a_0 i dobijemo kvadratnu jednacinu po k):

            a_0 = (n - k*(k - 1)/2) / k;
            Posto a_0 treba da bude ceo broj, potrebno je samo ispitati da li je
            (n - k*(k - 1)/2) % k == 0.

            Iz jednacine k*a_0 + k*(k - 1)/2 = n, dobijamo:
                k + k*(k - 1)/2 <= n, posto je a_0 >= 1
            
            k inicijalizujemo na 2 (po uslovu zadatka se ocekuje zbir dva ili vise 
            uzastopna prirodna broja)
    */
    
    unsigned brojac = 0;
    for (unsigned k = 2; k + k*(k - 1)/2 <= n; k++)
    {
        if ((n - k*(k - 1)/2) % k == 0)
        {
            brojac++;
        }
    }
    
    cout << brojac << endl;

    return 0;
}