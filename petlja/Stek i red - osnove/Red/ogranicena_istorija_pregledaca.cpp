#include <iostream>
#include <deque>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    string linija;
    deque<string> istorija;
    while (cin >> linija)
    {
        if (linija == "back")
        {
            if (!istorija.empty())
            {
                istorija.pop_back();
            }

            if (istorija.empty())
            {
                cout << "-" << '\n';    
            }
            else
            {
                cout << istorija.back() << '\n';
            }
        }
        else
        {
            cout << linija << '\n';
            istorija.push_back(linija);
        }

        if (istorija.size() == n + 1)
        {
            istorija.pop_front();
        }
    }

    return 0;
}