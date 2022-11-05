#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    /* suma[k = 0, inf] {(-1)^k / (2k + 1)} */
    int n;
    cin >> n;
    
    vector<double> sume(n);
    int trenutniZnak = 1;
    double trenutniSabirak;
    double trenutnaSuma = 0;
    for (int i = 0; i < n; i++)
    {
        trenutniSabirak = (double)trenutniZnak / (2 * i + 1);
        trenutniZnak *= -1; 
        trenutnaSuma += trenutniSabirak;
        sume[i] = trenutnaSuma;
    }

    cout << fixed << setprecision(5) << showpoint << 4*trenutnaSuma << '\n';
    // *4 jer data suma daje pribliznu vrednost Pi/4, a nama treba priblizna vrednost Pi
    
    for (int i = 0; i < n; i++)
    {
            cout << fixed << setprecision(5) << showpoint<< 4*sume[i] << '\n';
    }
    
    return 0;
}