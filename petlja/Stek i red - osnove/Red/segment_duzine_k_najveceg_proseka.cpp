#include <iostream>
#include <queue>


using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;

    queue<double> segmentDuzineK;
    // koristimo zbir jer ga je lakse odrzavati,
    // a rezultat ce ostati isti
    double zbir = 0.0;
    double maxZbir = 0.0;
    int pocetakMaxSegmenta = -1;
    for (int i = 0; i < n; i++)
    {
        double br;
        cin >> br;
        
        zbir += br;
        segmentDuzineK.push(br);

        if (segmentDuzineK.size() == k)
        {
            if (maxZbir <= zbir)
            {
                maxZbir = zbir;
                pocetakMaxSegmenta = i + 1 - k;
            }

            zbir -= segmentDuzineK.front();
            segmentDuzineK.pop();
        }
    }
    
    cout << pocetakMaxSegmenta << endl;

    return 0;
}