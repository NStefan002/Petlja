#include <iostream>
#include <queue>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int k;
    cin >> k;
    
    string linija;
    queue<string> poslednjihK;
    while (getline(cin, linija))
    {
        poslednjihK.push(linija);

        if (poslednjihK.size() > k)
        {
            poslednjihK.pop();
        }
    }

    while (!poslednjihK.empty())
    {
        cout << poslednjihK.front() << endl;
        poslednjihK.pop();
    }

    return 0;
}