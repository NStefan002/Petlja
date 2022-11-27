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

    vector<int> maxRazlike(n - 1);
    int minAkcija, akcija;
    cin >> minAkcija;
    for (int i = 1; i < n; i++)
    {
        cin >> akcija;
        int razlika = akcija - minAkcija;
        maxRazlike[i - 1] = (razlika <= 0)? 0 : razlika;

        minAkcija = min(minAkcija, akcija); 
    }

    int maxRazlika = 0;
    for (int i = 0; i < n - 1; i++)
    {
        maxRazlika = max(maxRazlika, maxRazlike[i]);
    }
    
    cout << maxRazlika << endl;

    return 0;
}