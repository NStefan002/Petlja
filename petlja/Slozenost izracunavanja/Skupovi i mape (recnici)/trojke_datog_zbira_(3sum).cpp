#include <iostream>
#include <vector>
#include <set>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> rejtinzi(n);

    for (int i = 0; i < n; i++)
    {
        cin >> rejtinzi[i];
    }
    
    set<int> skup;
    skup.insert(rejtinzi[0]);

    int brTrojki = 0;
    /* proveravamo da li u delu niza sa indeksima manjim od i postoji 
    element koji sa elementima na indeksima i i j cini trojku */
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (skup.find(-(rejtinzi[i] + rejtinzi[j])) != skup.end())
            {
                brTrojki++;
            }
        }
        skup.insert(rejtinzi[i]);
    }
    
    cout << brTrojki << endl;

    return 0;
}