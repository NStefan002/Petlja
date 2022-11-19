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

    vector<int> paketi(n);

    for (int i = 0; i < n; i++)
    {
        cin >> paketi[i];
    }

    int k;
    cin >> k;
    
    sort(begin(paketi), end(paketi));
    
    int minRazlika = paketi[k - 1] - paketi[0];
    for (int i = 1; i + k - 1 < n; i++)
    {
        minRazlika = min(minRazlika, paketi[i + k - 1] - paketi[i]);
    }

    cout << minRazlika << endl;

    return 0;
}