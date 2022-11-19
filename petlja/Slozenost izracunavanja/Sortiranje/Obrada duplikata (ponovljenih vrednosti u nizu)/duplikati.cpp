#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    
    int n;
    cin >> n;

    vector<unsigned> IPAdrese(n);

    for (int i = 0; i < n; i++)
    {
        cin >> IPAdrese[i];
    }
    
    sort(begin(IPAdrese), end(IPAdrese));

    int brojRazlicitih = 1; // prva adresa u sortiranom nizu
    for (int i = 1; i < n; i++)
    {
        if (IPAdrese[i] != IPAdrese[i - 1])
        {
            brojRazlicitih++;
        }
    }
    
    cout << brojRazlicitih << endl;

    return 0;
}