#include <iostream>
#include <vector>


using namespace std;

int najveciProsek(int k, const vector<double>& a);

int main()
{
    int k, n;
    cin >> k >> n;

    vector<double> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    cout << najveciProsek(k, a) << endl;

    return 0;
}

int najveciProsek(int k, const vector<double>& a)
{
    int n = a.size();

    // za odredjivanje maksimuma svejedno je da li cemo racunati
    // sumu ili prosek, sumu je lakse koristiti zbog inkrementalnosti
    double trSuma = 0;

    // racunanje sume prvih k elemenata
    for (int i = 0; i < k; i++)
    {
        trSuma += a[i];
    }
    
    double maxSuma = trSuma;
    int maxIndex = 0;
    for (int i = k; i < n; i++)
    {
        trSuma -= a[i - k];
        trSuma += a[i];

        if (maxSuma <= trSuma)
        {
            maxSuma = trSuma;
            maxIndex = i - k + 1;
        }
    }
    
    return maxIndex;
}