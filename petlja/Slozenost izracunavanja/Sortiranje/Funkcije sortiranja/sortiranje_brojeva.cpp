#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> brojevi(n);

    for (int i = 0; i < n; i++)
    {
        cin >> brojevi[i];
    }
    
    sort(begin(brojevi), end(brojevi));

    for (int i = 0; i < n; i++)
    {
        cout << brojevi[i] << '\n';
    }

    return 0;
}