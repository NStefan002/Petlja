#include <iostream>


using namespace std;

int main()
{
    string originalnaPutanja, sazetaPutanja = "";
    cin >> originalnaPutanja;    

    for (auto c : originalnaPutanja)
    {
        if (sazetaPutanja.empty())
        {
            sazetaPutanja.push_back(c);
        }
        else 
        {
            switch (c)
            {
            case 'L':
                if (sazetaPutanja.back() == 'R')
                {
                    sazetaPutanja.pop_back();
                }
                else
                {
                    sazetaPutanja.push_back(c);
                }
                break;

            case 'R':
                if (sazetaPutanja.back() == 'L')
                {
                    sazetaPutanja.pop_back();
                }
                else
                {
                    sazetaPutanja.push_back(c);
                }
                break;
                
            case 'D':
                if (sazetaPutanja.back() == 'U')
                {
                    sazetaPutanja.pop_back();
                }
                else
                {
                    sazetaPutanja.push_back(c);
                }
                break;
                
            case 'U':
                if (sazetaPutanja.back() == 'D')
                {
                    sazetaPutanja.pop_back();
                }
                else
                {
                    sazetaPutanja.push_back(c);
                }
                break;
            default:
                break;
            }
        }
    }
    
    cout << sazetaPutanja << endl;

    return 0;
}