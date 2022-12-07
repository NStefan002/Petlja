#include <iostream>
#include <stack>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string sajt;
    stack<string> istorijaPretrage;

    while (getline(cin, sajt))
    {
        if (sajt == "back")
        {
            if (!istorijaPretrage.empty())
            {
                // skidamo poslednju stranicu sa steka
                istorijaPretrage.pop();
            }
            // ponovo proveravamo da li je stek prazan (zbog prethodnog pop-a)
            if (!istorijaPretrage.empty())
            {
                cout << istorijaPretrage.top() << '\n';
            }
            else
            {
                cout << "-" << '\n';
            }
        }
        // ispisujemo novoposeceni sajt i dodajemo ga na stek
        else
        {
            cout << sajt << '\n';
            istorijaPretrage.push(sajt);
        }
    }

    cout << endl;

    return 0;
}