#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> varijacija(k);
    for (int i = 0; i < k; i++)
    {
        cin >> varijacija[i];
    }
    
    int i;
    for (i = varijacija.size() - 1; i >= 0; i--)
    {
        if (varijacija[i] == n)
        {
            varijacija[i] = 1;
        }
        else
        {
            varijacija[i]++;
            break;
        }
    }
    
    // ako su svi elementi bili jednaki n
    if (i == -1)
    {
        cout << '-';
    }
    else
    {
        for (int x : varijacija)
        {
            cout << x << ' ';
        }
    }
    
    cout << endl;
    return 0;
}