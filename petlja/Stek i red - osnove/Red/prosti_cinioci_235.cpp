#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<int64_t> q2, q3, q5;

    q2.push(2);
    q3.push(3);
    q5.push(5);

    int64_t tek_min = 1; // prvi broj obradjen pre petlje
    for (int i = 0; i < n; i++)
    {
        tek_min = min({q2.front(), q3.front(), q5.front()});

        if (tek_min == q2.front())
        {
            q2.pop();
        }
        if (tek_min == q3.front())
        {
            q3.pop();
        }
        if (tek_min == q5.front())
        {
            q5.pop();
        }

        q2.push(2 * tek_min);
        q3.push(3 * tek_min);
        q5.push(5 * tek_min);
    }
    
    cout << tek_min << endl;

    return 0;
}