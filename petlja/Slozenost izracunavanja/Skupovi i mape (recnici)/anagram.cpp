#include <iostream>
#include <map>
#include <cctype>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    map<char, int> brPojavljivanjaSlova1;
    for (int i = 0; s1[i]; i++)
    {
        if (isalpha(s1[i]))
        {
            brPojavljivanjaSlova1[s1[i]]++;
        }
    }
    

    map<char, int> brPojavljivanjaSlova2;
    for (int i = 0; s2[i]; i++)
    {
        if (isalpha(s2[i]))
        {
            brPojavljivanjaSlova2[s2[i]]++;
        }
    }

    cout << ((brPojavljivanjaSlova1 == brPojavljivanjaSlova2)? "da" : "ne") << endl;

    return 0;
}