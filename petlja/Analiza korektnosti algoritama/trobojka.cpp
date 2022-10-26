#include <iostream>
#include <vector>

void ispisi_niz(std::vector<int>& v);
void trobojka(std::vector<int>& niz, int A, int B);
void swap(std::vector<int>& niz, int i, int j);

int main() 
{   
    int n, A, B;
    std::cin >> n;
    std::vector<int> niz(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> niz[i];
    }
    
    std::cin >> A;
    std::cin >> B;
    // std::cout << A << ' ' << B << '\n';
    trobojka(niz, A, B);
    for (int x : niz)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    // ispisi_niz(niz);

    return 0;
}

void ispisi_niz(std::vector<int>& v)
{
    for (int x : v)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

void trobojka(std::vector<int>& niz, int A, int B)
{
    //          l          i       d
    // a a a a ab ab ab ab ? ? ? ? b b b b b
    int l = 0, d = niz.size(), i = 0;
    
    while (i < d)
    {
        if (niz[i] < A)
        {
            swap(niz, i++, l++);
        }
        else if (niz[i] > B)
        {
            swap(niz, i, --d);
        }
        else // ako niz[i] pripada [A, B]
        {
            i++;
        }
    }
}

void swap(std::vector<int>& niz, int i, int j)
{
    int tmp = niz[i];
    niz[i] = niz[j];
    niz[j] = tmp;
}