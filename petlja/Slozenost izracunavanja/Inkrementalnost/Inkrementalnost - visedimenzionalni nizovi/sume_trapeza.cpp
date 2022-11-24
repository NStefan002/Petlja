#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    
    vector<vector<int>> B(n, vector<int>(n, 0));

    /* Vrednost elementa B[i][j] moze se racunati inkrementalno (ne moramo svaki put iz
    pocetka prolaziti matricu A i racunati sume). Mozemo uvideti da je vrednost B[i][j]
    jednaka sumi svih elemenata i-te vrste matrice a na indeksima [0, j] plus 
    element B[i - 1][j + 1] ako taj element postoji, odnosno B[i - 1][j] (naravno, 
    za nultu vrstu se u obzir uzima samo suma prvih j elemenata matrice A).  */
    for (int i = 0; i < n; i++)
    {
        int sumaVrste = 0;
        for (int j = 0; j < n; j++)
        {
            sumaVrste += A[i][j];

            if (i > 0)
            {
                B[i][j] += (j < n - 1)? B[i - 1][j + 1] : B[i - 1][j];
            }
            
            B[i][j] += sumaVrste;
        }
    }
    
    // ispis
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << B[i][j] << ' ';
        }
        
        cout << '\n';
    }
    

    return 0;
}