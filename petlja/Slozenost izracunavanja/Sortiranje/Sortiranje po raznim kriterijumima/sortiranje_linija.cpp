#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>


using namespace std;

int main()
{
    vector<string> linije;
    string linija;
    while (cin >> linija)
    {
        linije.push_back(linija);
    }

    sort(begin(linije), end(linije),
    [] (const string& s1, const string& s2)
    {
        for (int i = 0; s1[i] && s2[i]; i++)
        {
            if (tolower(s1[i]) < tolower(s2[i]))
            {
                return true;
            }

            if (tolower(s1[i]) > tolower(s2[i]))
            {
                return false;
            }
        }
        
        return s1.length() < s2.length();
    });


    for (auto lin : linije)
    {
        cout << lin << '\n';
    }

    return 0;
}