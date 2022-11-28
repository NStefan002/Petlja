#include <iostream>
#include <vector>


using namespace std;

struct koordinatePravougaonika
{
    // indeksi po vrstama i kolonama
    int v1, k1;
    int v2, k2;
};

int ocenaPravougaonika(vector<vector<int>>& sume, koordinatePravougaonika& koord);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> sumeKvadrata(n, vector<int>(n));

    // posebno ucitavamo prvu vrstu
    cin >> sumeKvadrata[0][0];
    for (int j = 1; j < n; j++)
    {
        cin >> sumeKvadrata[0][j];
        sumeKvadrata[0][j] += sumeKvadrata[0][j - 1];
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int kvadrat;
            cin >> kvadrat;
            
            sumeKvadrata[i][j] = ((j == 0)? sumeKvadrata[i - 1][n - 1] : sumeKvadrata[i][j - 1]) + kvadrat;
        }
    }
    
    int m;
    cin >> m;
    
    koordinatePravougaonika koord;
    for (int i = 0; i < m; i++)
    {
        cin >> koord.v1 >> koord.k1 >> koord.v2 >> koord.k2;
        cout << ocenaPravougaonika(sumeKvadrata, koord) << '\n';
    }

    return 0;
}

int ocenaPravougaonika(vector<vector<int>>& sume, koordinatePravougaonika& koord)
{
    // odredjujemo "granice" pravougaonika
    int minV, maxV, minK, maxK;
    minV = (koord.v1 < koord.v2)? koord.v1 : koord.v2;
    maxV = (koord.v1 > koord.v2)? koord.v1 : koord.v2;

    minK = (koord.k1 < koord.k2)? koord.k1 : koord.k2;
    maxK = (koord.k1 > koord.k2)? koord.k1 : koord.k2;

    /* Ukupnu ocenu racunamo kao zbir elemenata unutar gore izracunatih granica.
    Posto na raspolaganju imamo sume ocena (suma na indeksu ij jednaka je zbiru svih
    ocena od indeksa 00 do indeksa ij ukljucujuci i njega), zbir unutar granica racunamo
    kao suma_MaxK - suma_(MaxK-1) i tako za svaku vrstu matrice (cime se dobija linearna
    vremenska slozenost u najgorem slucaju). Naravno, moramo uzeti u obzir par izuzetaka
    (u slucajevima kada su indeksi na granicima), ali sem toga ideja ostaje ista. */
    int ocena = 0;
    for (int i = minV; i <= maxV; i++)
    {
        if (minK == 0)
        {
            /*  */
            ocena += sume[i][maxK] - ((i == 0)? 0 : sume[i - 1][sume.size() - 1]);
        }
        else
        {
            ocena += sume[i][maxK] - sume[i][minK - 1];
        }
    }
    
    return ocena;
}