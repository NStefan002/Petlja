#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    map<string, int> glasovi;
    for (int i = 0; i < n; i++)
    {
        string ime;
        cin >> ime;
        glasovi[ime]++;
    }
    
    int maxGlasova = 0;
    // p je pair<string, int>
    for (auto p : glasovi)
    {
        maxGlasova = max(maxGlasova, p.second);
    }
    
    cout << maxGlasova << endl;

    return 0;
}