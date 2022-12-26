#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    queue<int> krugDjaka;
    for (int i = 0; i < n; i++)
    {
        krugDjaka.push(i);
    }
    
    while (krugDjaka.size() > 1)
    {
        // m-1 djaka prebacujemo na kraj kruga, a m-tog djaka izbacujemo
        for (int i = 1; i < m; i++)
        {
            krugDjaka.push(krugDjaka.front());
            krugDjaka.pop();
        }
        // m-ti djak
        krugDjaka.pop();
    }

    cout << krugDjaka.front() << endl;
    
    return 0;
}