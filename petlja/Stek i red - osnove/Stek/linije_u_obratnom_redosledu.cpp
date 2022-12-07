#include <iostream>
#include <stack>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<string> linije;
    string linija;
    while (getline(cin, linija))
    {
        linije.push(linija);
    }

    while (!linije.empty())
    {
        cout << linije.top() << '\n';
        linije.pop();
    }

    return 0;
}