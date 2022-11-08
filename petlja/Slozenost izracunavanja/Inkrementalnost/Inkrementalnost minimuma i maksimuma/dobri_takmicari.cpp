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
    
    vector<pair<int, int>> takmicari(n);


    for (int i = 0; i < n; i++)
    {
        cin >> takmicari[i].first >> takmicari[i].second;
    }
    
    int brDobrih = 0;
    for (int i = 0; i < n; i++)
    {
        bool jesteDobar = true;
        for (int j = 0; j < n; j++)
        {
            if (takmicari[i].first < takmicari[j].first && takmicari[i].second < takmicari[j].second)
            {
                jesteDobar = false;
                break;
            }            
        }
        if (jesteDobar)
        {
            brDobrih++;
        }
        
    }
    
    
    cout << brDobrih << endl;

    return 0;
}