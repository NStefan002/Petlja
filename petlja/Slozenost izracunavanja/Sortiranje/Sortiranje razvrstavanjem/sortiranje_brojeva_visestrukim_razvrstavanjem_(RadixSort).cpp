#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void razvrstavanjePoCiframa(vector<uint64_t>& niz, int desetNaStepen);
void RadixSort(vector<uint64_t>& niz);

int main()
{
    int n;
    cin >> n;

    vector<uint64_t> niz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }
    
    RadixSort(niz);

    for (int i = 0; i < n; i++)
    {
        cout << niz[i] << '\n';
    }
    
    return 0;
}

void razvrstavanjePoCiframa(vector<uint64_t>& niz, int desetNaStepen)
{
    // cuvamo pozicije elemenata u sortiranom nizu
    vector<int> pom(10, 0);
    
    // razvrstavamo elemente po odgovarajucoj cifri
    for (auto br : niz)
    {
        pom[(br / desetNaStepen) % 10]++;
    }

    // inkrementalno azuriramo pozicije
    for (int i = 1; i < 10; i++)
    {
        pom[i] += pom[i - 1];
    }
    
    vector<uint64_t> sortiran(niz.size());
    
    for (int i = niz.size() - 1; i >= 0; i--)
    {
        sortiran[--pom[(niz[i] / desetNaStepen) % 10]] = niz[i];
    }
    
    niz = sortiran;
}

void RadixSort(vector<uint64_t>& niz)
{
    uint64_t max = *max_element(begin(niz), end(niz));

    for (uint64_t stepenDesetke = 1; max / stepenDesetke > 0; stepenDesetke *= 10)
    {
        razvrstavanjePoCiframa(niz, stepenDesetke);
    }
}