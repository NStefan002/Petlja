#include <iostream>
#include <vector>


using namespace std;

const int n = 9;

bool validnoPopunjenoPolje(vector<string> &sudoku, int i, int j);
pair<int, int> pronadjiPrvoPraznoPolje(vector<string> &sudoku, int i, int j);
bool popuniSudoku(vector<string> &sudoku, int i, int j);

int main()
{
    vector<string> sudoku(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sudoku[i];
    }
    
    /* pretpostavljamo da resenje postoji pa ne proveravamo da li je 
    funkcija vratila false */
    popuniSudoku(sudoku, 0, 0);

    // cout << "\n\n";
    for (auto vrsta : sudoku)
    {
        cout << vrsta << '\n';
    }
    
    return 0;
}

bool popuniSudoku(vector<string> &sudoku, int i, int j)
{
    if (sudoku[i][j] != '0' && !validnoPopunjenoPolje(sudoku, i, j))
    {
        return false;
    }
    
    pair<int, int> i_j = pronadjiPrvoPraznoPolje(sudoku, i, j);
    i = i_j.first; j = i_j.second;

    // ukoliko je sudoku popunjen
    if (i == -1)
    {
        return true;
    }
    
    char br;
    for (br = 1; br <= 9; br++)
    {
        sudoku[i][j] = br + '0';
        if (popuniSudoku(sudoku, i, j))
        {
            break;
        }
    }
    
    /* ukoliko na trenutno polje ne moze da se upise nijedan broj,
    oznacavamo ga kao prazno i vracamo false prethodnom rekurzivnom pozivu
    (koji onda zna da mora svoj trenutni element da promeni inace ne moze dobiti
    validno resenje) */
    if (br > 9)
    {
        sudoku[i][j] = '0';
        return false;
    }
    
    return true;
}

pair<int, int> pronadjiPrvoPraznoPolje(vector<string> &sudoku, int i, int j)
{
    while (i < n)
    {
        while (j < n)
        {
            if (sudoku[i][j] == '0')
            {
                return {i, j};
            }
            j++;
        }   
        i++;
        j = 0;
    }

    // sva polja popunjena
    return {-1, -1};
}

bool validnoPopunjenoPolje(vector<string> &sudoku, int i, int j)
{
    for (int vrsta = 0; vrsta < n; vrsta++)
    {
        if (vrsta != i && sudoku[vrsta][j] == sudoku[i][j])
        {
            return false;
        }
    }
    
    for (int kolona = 0; kolona < n; kolona++)
    {
        if (kolona != j && sudoku[i][kolona] == sudoku[i][j])
        {
            return false;
        }
    }

    int pocetakKvadrata_i = (i / 3) * 3;
    int pocetakKvadrata_j = (j / 3) * 3;
    for (int kvadratVrsta = pocetakKvadrata_i; kvadratVrsta < pocetakKvadrata_i + 3; kvadratVrsta++)
    {
        for (int kvadratKolona = pocetakKvadrata_j; kvadratKolona < pocetakKvadrata_j + 3; kvadratKolona++)
        {
            if ((kvadratVrsta != i || kvadratKolona != j) && sudoku[kvadratVrsta][kvadratKolona] == sudoku[i][j])
            {
                return false;
            }
        }
    }
    
    return true;
}