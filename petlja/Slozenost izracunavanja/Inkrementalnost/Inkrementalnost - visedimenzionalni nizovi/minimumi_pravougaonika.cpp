#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> A(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    
    // menjamo matricu A
    /* Trenutni element je najmanji od sledeca tri elementa:
            - trenutni element
            - element levo od njega u matrici (ukoliko postoji)
            - element iznad njega u matrici (ukoliko postoji) */
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
            {
                A[i][j] = min(A[i][j], A[i][j - 1]);
            }
            
            if (i > 0)
            {
                A[i][j] = min(A[i][j], A[i - 1][j]);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << ' '; 
        }
        cout << '\n';
    }
    

    return 0;
}