#include <iostream>


using namespace std;

int main()
{
    uint64_t a, b, k;
    cin >> a >> b >> k;

    /* 
        [0, b]: 1 + b/k, +1 jer je nula deljiva sa bilo kojim k,
        a / je celobrojno deljenje
        [0, a-1]: 1 + (a - 1)/k

        [a,b] = [0, b] - [0, a-1]
        [a, b]: 1 + b/k - (1 + (a - 1)/k) = b/k - (a - 1)/k != (b - a - 1)/k, jer je 
        u pitanju celobrojno deljenje 
    */

    uint64_t nulaDoA = (a == 0)? 0 : (a - 1)/k + 1;
    uint64_t nulaDoB = b/k + 1;
    uint64_t rez = nulaDoB - nulaDoA;

    cout << rez << '\n';

    return 0;
}