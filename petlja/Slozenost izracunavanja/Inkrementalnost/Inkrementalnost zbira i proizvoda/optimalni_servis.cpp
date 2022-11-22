#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> kilometraza(n);

    // suma do i od servisa
    int levaSuma = 0, desnaSuma = 0;
    for (int i = 0; i < n; i++)
    {
        int km;
        cin >> km;
        kilometraza[i] = km;
        desnaSuma += km;
    }

    int minIndex = 0;
    int minRazlika = desnaSuma;

    for (int i = 0; i < n; i++)
    {
        levaSuma += kilometraza[i];
        desnaSuma -= kilometraza[i];

        int trRazlika = abs(levaSuma - desnaSuma);
        if (minRazlika > trRazlika)
        {
            minRazlika = trRazlika;
            minIndex = i;
        }
    }
    
    cout << minIndex << endl;

    return 0;
}