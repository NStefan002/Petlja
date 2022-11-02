#include <iostream>


using namespace std;

unsigned brPodnizova(unsigned brJedinica);

int main()
{
    string s;
    cin >> s;

    unsigned brJedinica = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '1')
        {
            brJedinica++;
        }
    }
    
    // cout << brPodnizova(brJedinica) << '\n';
    cout << (brJedinica * (brJedinica - 1) / 2) << '\n';

    return 0;
}

unsigned brPodnizova(unsigned brJedinica)
{
    unsigned rez = 0;
    for (unsigned i = 1; i < brJedinica; i++)
    {
        rez += i;
    }
    
    return rez;
}