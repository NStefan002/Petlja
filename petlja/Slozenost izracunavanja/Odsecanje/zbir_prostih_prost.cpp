#include <iostream>
#include <vector>

using namespace std;
void EratostenovoSito(vector<bool>& prosti, unsigned n);
unsigned brParova(const vector<bool>& prosti, unsigned n);

int main()
{
    unsigned n;
    cin >> n;

    vector<bool> prosti;
    EratostenovoSito(prosti, n);
    
    cout << brParova(prosti, n) << endl;

    return 0;
}

void EratostenovoSito(vector<bool>& prosti, unsigned n)
{
    prosti.resize(n, true);
    prosti[0] = false;

    for (unsigned i = 2; i * i <= n; i++)
    {
        if (prosti[i - 1])
        {
            for (unsigned j = i * i; j <= n; j += i)
            {
                prosti[j - 1] = false;
            }
        }
    }
}

unsigned brParova(const vector<bool>& prosti, unsigned n)
{
    unsigned brojac = 0;
    unsigned p = 2;
    /* Svi prosti brojevi nakon 2 su neparni, tkd. zbir bilo koja dva od njih
    ce biti paran (odnosno nece biti prost). Zbog toga se za prvi sabirak uzima
    samo 2. */
    for (unsigned q = p + 1; p + q <= n; q += 2)
    {
        if (prosti[q - 1] && prosti[p + q - 1])
        {
            brojac++;
        }
    }
    
    
    return brojac;
}