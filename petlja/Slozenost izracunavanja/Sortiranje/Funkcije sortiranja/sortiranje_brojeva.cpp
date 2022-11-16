#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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