#include <iostream>
#include <vector>


using namespace std;

int zaradaPerioda(pair<int, int>& upit, const vector<int>& prefiksneSume);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> prefiksneSume(n + 1, 0);

    int zarada;
    for (int i = 0; i < n; i++)
    {
        cin >> zarada;
        prefiksneSume[i + 1] += prefiksneSume[i] + zarada;
    }

    int m;
    cin >> m;

    pair<int, int> upit;
    for (int i = 0; i < m; i++)
    {
        cin >> upit.first >> upit.second;
        cout << zaradaPerioda(upit, prefiksneSume) << '\n';
    }

    return 0;
}

int zaradaPerioda(pair<int, int>& upit, const vector<int>& prefiksneSume)
{
    return prefiksneSume[upit.second + 1] - prefiksneSume[upit.first];
}