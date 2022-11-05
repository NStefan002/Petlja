#include <iostream>
#include <vector>


using namespace std;

bool jesteProst(unsigned x);
void EratostenovoSito(vector<bool>& prosti, unsigned b);

int main()
{
    unsigned a, b;
    cin >> a >> b;

    vector<bool> prosti(b, true);
    EratostenovoSito(prosti, b);

    unsigned long zbirProstih = 0;
    unsigned brProstih = 0;
    for (unsigned i = a - 1; i < b; i++)
    {
        if (prosti[i])
        {
            zbirProstih = (zbirProstih + i + 1) % (unsigned)1e6; // +1 jer je indeks broja u nizu
            // prostih za jedan manji od samog broja
            brProstih++;
        }
    }

    cout << brProstih << ' ' << zbirProstih << endl;   

    return 0;
}

bool jesteProst(unsigned x)
{
    if ((x % 2 == 0 && x != 2) || x == 1)
    {
        return false;
    }
    
    for (unsigned i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

void EratostenovoSito(vector<bool>& prosti, unsigned b)
{
    prosti[0] = false;
    for (unsigned i = 2; i * i <= b; i++)
    {
        if (prosti[i - 1] && jesteProst(i))
        {
            unsigned j = i * i;
            while (j <= b)
            {
                prosti[j - 1] = false;
                j += i;
            }
        }
    }
}