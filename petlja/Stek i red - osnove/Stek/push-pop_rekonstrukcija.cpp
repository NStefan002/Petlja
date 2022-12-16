#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int main()
{
    int n;
    cin >> n;
        
    vector<int> pocetni(n), krajnji(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pocetni[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> krajnji[i];
    }

    stack<int> stek;
    vector<string> ispis;
    int i = 0, j = 0;
    while (i < n || j < n)
    {
        if (i < n && (stek.empty() || stek.top() != krajnji[j]))
        {
            ispis.push_back("push");
            stek.push(pocetni[i++]);
        }
        else if (j < n && (!stek.empty() && stek.top() == krajnji[j]))
        {
            j++;
            ispis.push_back("pop");
            stek.pop();
        }
        else
        {
            ispis.clear();
            ispis.push_back("-");
            break;
        }
    }
    
    for (auto s : ispis)
    {
        cout << s << endl;
    }

    return 0;
}