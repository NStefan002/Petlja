#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void pretvoriUKanonskiOblik(vector<int>& niz, int d);
bool istiKanonskiOblik(vector<int>& niz, vector<int>& kanonskiOblik);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int d, k, n;
    cin >> d >> k >> n;

    vector<vector<int>> nizovi(n, vector<int>(k));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> nizovi[i][j];
        }

        /* pretvaramo nizove u svoje kanonske oblike
        da bi ih lakse uporedjivali kasnije */
        pretvoriUKanonskiOblik(nizovi[i], d);
    }
   
    for (int i = 1; i < n; i++)
    {
        cout << (istiKanonskiOblik(nizovi[i], nizovi[0])? "da" : "ne") << '\n';
    }

    return 0;
}

void pretvoriUKanonskiOblik(vector<int>& niz, int d)
{
    int n = niz.size();

    vector<int> pom(n/d + 1);
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        /* izdvajanje svih elemenata na rastojanju d
        pocev od i-tog */
        for (int j = i; j < n; j += d)
        {
            pom[k++] = niz[j];
        }
        /* sortiranje prvih k elemenata pomocnog niza */
        sort(begin(pom), begin(pom) + k);

        k = 0;
        /* upisivanje sadrzaja pomocnog niza nazad u 
        originalni niz, kada se upisu svi pomocni nizovi
        niz ce biti u kanonskom obliku */
        for (int j = i; j < n; j += d)
        {
            niz[j] = pom[k++];
        }
    }
}

bool istiKanonskiOblik(vector<int>& niz, vector<int>& kanonskiOblik)
{
    int n = niz.size();
    for (int i = 0; i < n; i++)
    {
        if (niz[i] != kanonskiOblik[i])
        {
            return false;
        }
    }
    
    return true;
}