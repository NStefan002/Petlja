#include <iostream>
#include <map>


using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, int> ponavljanjaElemenata1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        ponavljanjaElemenata1[x]++;
    }

    int m;
    cin >> m;

    map<int, int> ponavljanjaElemenata2;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        ponavljanjaElemenata2[x]++;
    }

    cout << ((ponavljanjaElemenata1 == ponavljanjaElemenata2)? "da" : "ne") << endl;

    return 0;
}